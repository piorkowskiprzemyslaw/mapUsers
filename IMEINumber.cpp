#include "IMEINumber.h"

/** \brief Domyslny konstruktor
 *
 * \param data unsigned char*
 * \param dataLength int
 *
 */
IMEINumber::IMEINumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
    this->nmb = 0;
}

/** \brief Domyslny destruktor
 */
IMEINumber::~IMEINumber() {}

/** \brief Metoda dekodujaca pole na numer IMEI
 *
 * \return void
 *
 */
void IMEINumber::decode()
{
    for(int i = 0 ; i < this->dataLength ; ++i)
    {
        std::pair<int, int> decodedPair = Helper::TBCDByteEncode(this->data[i]);

        if(decodedPair.first == 15)
        {
            break;
        }else{
            this->number.push_back(decodedPair.first);
        }
        if(decodedPair.second == 15)
        {
            break;
        }else{
            this->number.push_back(decodedPair.second);
        }
    }

    int i = 1;

    for(std::list<unsigned char>::iterator it = this->number.begin() ; it != this->number.end() ; ++it, ++i)
    {
        nmb += ((unsigned long)(*it)) * Helper::power((unsigned long)10, (unsigned long)(this->number.size() - i));
    }
}

/** \brief zwrocenie numeru IMEI w postaci listy
 *
 * \return std::list<unsigned char>
 *
 */
std::list<unsigned char> IMEINumber::getAsList()
{
    return this->number;
}

/** \brief Zwrocenie numeru IMEI w postaci liczby
 *
 * \return unsigned long
 *
 */
unsigned long IMEINumber::getAsNumber()
{
    return this->nmb;
}

/** \brief Wypisanie numeru IMEI
 *
 * \return void
 *
 */
void IMEINumber::writeNumber()
{
    for(std::list<unsigned char>::iterator it = this->number.begin() ;
        it != this->number.end() ; ++it)
    {
        std::cout << int(*it) << " ";
    }
    std::cout << '\n';
}
