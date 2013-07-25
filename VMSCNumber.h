#ifndef VMSCNUMBER_H
#define VMSCNUMBER_H

#include <iostream>
#include <list>
#include "Helper.h"

/** \brief Klasa reprezentujaca pole VMSC
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class VMSCNumber
{
    private:
        unsigned char * data;
        int dataLength;
        std::list<unsigned char> number;
        unsigned long nmb;
        unsigned char extensionByte;
    public:
        VMSCNumber(unsigned char* data, int dataLength);
        ~VMSCNumber();
        void decode();
        std::list<unsigned char> getAsList();
        unsigned long getAsNumber();
        unsigned char getExtensionByte();
};

#endif // VMSCNUMBER_H
