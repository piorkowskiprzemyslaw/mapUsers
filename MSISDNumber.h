#ifndef MSISDNUMBER_H
#define MSISDNUMBER_H

#include <iostream>
#include <list>
#include "Helper.h"

/**
 * \brief Klasa reprezentujaca numer MSISDN
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class MSISDNumber
{
    private:
        unsigned char * data;
        int dataLength;
        unsigned char extensionByte;
        std::list<unsigned char> number;

    public:
        MSISDNumber(unsigned char * data, int dataLength);
        ~MSISDNumber();
        void decode();
};

#endif // MSISDNUMBER_H
