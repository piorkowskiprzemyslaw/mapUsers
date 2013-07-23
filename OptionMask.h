#ifndef OPTIONMASK_H
#define OPTIONMASK_H

#include <iostream>
#include <map>
#include "FieldName.h"

/**
 * \brief Klasa odpowiedzialna za dekodowanie pola option mask
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class OptionMask
{
    private:
        /**< pierwszy bajt option mask */
        unsigned char firstByte;
        /**< drugi bajt option mask */
        unsigned char secondByte;
        /**< cala maska w jednej zmiennej */
        unsigned short mask;
        /**< mapa option mask */
        std::map<FieldName, bool> optionMaskMap;
        /**< tablica do szybkiego odwracania kolejnosci bitow */
        static const unsigned char BitReverseTable256[256];

    public:
        OptionMask(unsigned char firstByte, unsigned char secondByte);
        bool decodeOptionMask();
        std::map<FieldName, bool>* getOptionMaskMap();
        ~OptionMask();
};

#endif // OPTIONMASK_H
