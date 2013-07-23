#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <utility>

/**
 * \brief Klasa pomocnicza z metodami przydatnymi w calym programie.
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class Helper
{
    private:

    public:
        Helper();
        virtual ~Helper();
        static std::pair<unsigned char, unsigned char> TBCDByteEncode(unsigned char byte);
};

#endif // HELPER_H
