#ifndef MSISDNUMBER_H
#define MSISDNUMBER_H

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <math.h>
#include "Helper.h"

/**
 * \brief Klasa reprezentujaca numer MSISDN
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class MSISDNumber
{
    private:
        /**< blok danych zawierajacy pole msisdn */
        unsigned char * data;
        /**< dlugosc bloku danych */
        int dataLength;
        /**< przedrostek przed msisdn */
        unsigned char extensionByte;
        /**< numer reprezentuje jako  lista powwiazana liczb */
        std::list<unsigned char> number;
        /**< numer reprezentowawny jako unsigned long */
        unsigned long nmb;
    public:
        MSISDNumber(unsigned char * data, int dataLength);
        ~MSISDNumber();
        void decode();
        std::list<unsigned char> getNumberAsList();
        unsigned long getNumberAsNumber();
        unsigned char getExtensionByte();
        void writeNumber();
};

#endif // MSISDNUMBER_H
