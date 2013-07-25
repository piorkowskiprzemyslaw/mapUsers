#include "IMSINumber.h"

/**
 * \brief Domyslny konstruktor
 */
IMSINumber::IMSINumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
    this->nmb = 0;
}

/**
 * \brief Domyslny destruktor
 */
IMSINumber::~IMSINumber() {}

/**
 * \brief Dekodowanie pola do numeru imsi
 */
void IMSINumber::decode()
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

/**
 * \brief Zwrocenie numeru w postaci listy
 * \return std::list<unsigned char>
 */
std::list<unsigned char> IMSINumber::getAsList()
{
    return this->number;
}

/**
 * \brief Zwrocenie numeru w postaci liczby
 * \return unsigned long
 *
 */
unsigned long IMSINumber::getAsNumber()
{
    return nmb;
}

/** \brief Wypisanie numeru IMSI
 *
 * \return void
 *
 */
void IMSINumber::writeNumber()
{
    for(std::list<unsigned char>::iterator it = this->number.begin() ;
        it != this->number.end() ; ++it)
    {
        std::cout << int(*it) << " ";
    }
    std::cout << '\n';
}
