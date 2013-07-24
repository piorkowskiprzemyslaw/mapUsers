#ifndef IMEINUMBER_H
#define IMEINUMBER_H

#include <iostream>
#include <list>
#include "Helper.h"

/** \brief Klasa reprezentujaca pole IMEI
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class IMEINumber
{
    private:
        unsigned char * data;
        int dataLength;
        std::list<unsigned char> number;
        unsigned long nmb;
    public:
        IMEINumber(unsigned char * data, int dataLength);
        ~IMEINumber();
        void decode();
        std::list<unsigned char> getNumberAsList();
        unsigned long getNumberAsNumber();
        void writeNumber();
};

#endif // IMEINUMBER_H
