#include "LAINumber.h"

/** \brief Domyslny konstruktor
 *
 * \param data unsigned char*
 * \param dataLength int
 *
 */
LAINumber::LAINumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
    this->lac = 0;
    this->mncNumber = 0;
}

/** \brief Domyslny destruktor
 */
LAINumber::~LAINumber() {}

/** \brief Metoda dekodujaca pole danych
 *
 * \return void
 *
 */
void LAINumber::decode()
{
    std::pair<unsigned int, unsigned int> decodedPair = Helper::TBCDByteEncode(this->data[2]);
    this->mnc.push_back(decodedPair.first);
    this->mnc.push_back(decodedPair.second);

    this->mncNumber = 10 * decodedPair.first;
    this->mncNumber += decodedPair.second;

    this->lac = this->data[3];
    this->lac = this->lac << 8 ;
    this->lac += this->data[4];
}

/** \brief Pobranie numeru LAI
 *
 * \return unsigned int
 *
 */
unsigned int LAINumber::getLAC()
{
    return this->lac;
}

/** \brief Pobieranie numeru mnc w postaci listy
 *
 * \return unsigned int
 *
 */
std::list<unsigned char> LAINumber::getMNCList()
{
    return this->mnc;
}

/** \brief Pobranie numeru mnc w postaci liczby
 *
 * \return unsigned int
 *
 */
unsigned int LAINumber::getMNCNumber()
{
    return this->mncNumber;
}
