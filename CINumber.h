#ifndef CINUMBER_H
#define CINUMBER_H

#include <iostream>

/** \brief Klasa reprezentujaca pole CI
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class CINumber
{
    private:
        /**< pole danych */
        unsigned char* data;
        /**< dlugosc pola danych */
        int dataLength;
        /**< numer CI po odkodowawniu */
        unsigned int number;
    public:
        CINumber(unsigned char* data, int dataLength);
        ~CINumber();
        void decode();
        unsigned int getNumber();
};

#endif // CINUMBER_H
