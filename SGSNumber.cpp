#include "SGSNumber.h"

/** \brief Domyslny konstruktor
 *
 * \param data unsigned char*
 * \param dataLength int
 *
 */
SGSNumber::SGSNumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
    this->nmb = 0;
}

/** \brief Domyslny destruktor
 */
SGSNumber::~SGSNumber() {}

/** \brief Metoda dekodujaca pole SGSN
 *
 * \return void
 *
 */
void SGSNumber::decode()
{
    this->extensionByte = this->data[0];
    std::pair<int, int> decodedPair;
    for(int i = 1 ; i < this->dataLength ; ++i)
    {
        decodedPair = Helper::TBCDByteEncode(this->data[i]);
        if(decodedPair.first == 15)
        {
            break;
        } else {
            this->number.push_back(decodedPair.first);
        }
        if(decodedPair.second == 15)
        {
            break;
        } else {
            this->number.push_back(decodedPair.second);
        }
    }
    int i = 1;
    for(std::list<unsigned char>::iterator it = this->number.begin() ; it != this->number.end() ; ++it, ++i)
    {
        nmb += ((unsigned long)(*it)) * Helper::power((unsigned long)10, (unsigned long)(this->number.size() - i));
    }
}

/** \brief Pobranie numeru w postaci listy powiazanej
 *
 * \return std::list<unsigned char>
 *
 */
std::list<unsigned char> SGSNumber::getAsList()
{
    return this->number;
}

/** \brief Pobranie w postaci liczby.
 *
 * \return unsigned long
 *
 */
unsigned long SGSNumber::getAsNumber()
{
    return this->nmb;
}

/** \brief Pobranie extension byte
 *
 * \return unsigned char
 *
 */
unsigned char SGSNumber::getExtensionByte()
{
    return this->extensionByte;
}
