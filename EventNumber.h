#ifndef EVENTNUMBER_H_
#define EVENTNUMBER_H_

#include <iostream>
#include "Helper.h"

/** \brief Klasa reprezentujaca numer reprezentujacy pole Event
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class EventNumber
{
    private:
        /**< Pole danych */
        unsigned char * data;
        /**< Dlugosc pola */
        int dataLength;
        /**< numer eventu */
        int number;
    public:
        EventNumber(unsigned char* data, int dataLength);
        ~EventNumber();
        void decode();
        int getEventNumber();
};

#endif // EVENTNUMBER_H
