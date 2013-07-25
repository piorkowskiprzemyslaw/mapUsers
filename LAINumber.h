#ifndef LAINUMBER_H
#define LAINUMBER_H


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
        /**< Zdekodowawny numer */
        unsigned int number;
    public:
        LAINumber(unsigned char * data, int dataLength);
        ~LAINumber();
        void decode();
        unsigned int getNumber();
};

#endif // LAINUMBER_H
