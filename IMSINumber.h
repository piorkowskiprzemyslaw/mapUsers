#ifndef IMSINUMBER_H
#define IMSINUMBER_H

#include <iostream>
#include <list>
#include "Helper.h"

/**
 * \brief Klasa przestawiajaca pole IMSI
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class IMSINumber
{
    private:
        /**< bajty z pola imsi */
        unsigned char * data;
        /**< ilosc bajtow do interpretacji */
        int dataLength;
        /**< reprezentacja numeru w postaci listy */
        std::list<unsigned char> number;
        /**< reprezentacja numeru w postaci liczby */
        unsigned long nmb;
    public:
        IMSINumber(unsigned char* data, int dataLength);
        ~IMSINumber();
        void decode();
        std::list<unsigned char> getNumberAsList();
        unsigned long getNumberAsNumber();
        void writeNumber();
};

#endif // IMSINUMBER_H
