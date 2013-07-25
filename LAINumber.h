#ifndef LAINUMBER_H
#define LAINUMBER_H

#include <iostream>
#include <list>
#include "Helper.h"

/** \brief Pole LAI
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class LAINumber
{
    private:
        /**< pole danych */
        unsigned char * data;
        /**< dlogosc pola danych */
        int dataLength;
        /**< Zdekodowawny lac */
        unsigned int lac;
        /**< Zdekodowany mnc */
        std::list<unsigned char> mnc;
        /**< mnc w postaci liczby */
        unsigned int mncNumber;
    public:
        LAINumber(unsigned char * data, int dataLength);
        ~LAINumber();
        void decode();
        unsigned int getLAC();
        std::list<unsigned char> getMNCList();
        unsigned int getMNCNumber();
};

#endif // LAINUMBER_H
