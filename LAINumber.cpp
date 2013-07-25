#include "LAINumber.h"

/** \brief Domyslny konstruktor
 *
 * \param data unsigned char*
 * \param dataLength int
 *
 */
LAINumber::LAINumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
    this->number = 0;
}

/** \brief Domyslny destruktor
 */
LAINumber::~LAINumber() {}

/** \brief Metoda dekodujaca pole danych
 *
 * \return void
 *
 */
void LAINumber::decode()
{
    this->number = this->data[3];
    this->number = this->number << 8 ;
    this->number += this->data[4];
}

/** \brief Pobranie numeru LAI
 *
 * \return unsigned int
 *
 */
unsigned int LAINumber::getNumber()
{
    return this->number;
}
