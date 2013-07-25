#ifndef SGSNUMBER_H
#define SGSNUMBER_H

#include <iostream>
#include <list>
#include "Helper.h"

/** \brief Klasa reprezentujaca pole SGSN
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class SGSNumber
{
    private:
        /**< pole pamieci z danymi */
        unsigned char * data;
        /**< dlugosc pola pamieci */
        int dataLength;
        /**< numer reprezentowny w postaci listy powiazanej */
        std::list<unsigned char> number;
        /**< numer reprezentowany w postaci liczby */
        unsigned long nmb;
        /**< extension byte zawarty w polu */
        unsigned char extensionByte;
    public:
        SGSNumber(unsigned char * data, int dataLength);
        ~SGSNumber();
        void decode();
        std::list<unsigned char> getAsList();
        unsigned long getAsNumber();
        unsigned char getExtensionByte();
};

#endif // SGSNUMBER_H
