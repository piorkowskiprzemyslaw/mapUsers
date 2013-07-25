#include "CINumber.h"

/** \brief Domyslny konstruktor
 *
 * \param data unsigned char*
 * \param dataLength int
 *
 */
CINumber::CINumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
    this->number = 0;
}

/** \brief Domyslny desktruktor
 */
CINumber::~CINumber() {}

/** \brief Metoda dekodujaca dane w polu
 *
 * \return void
 *
 */
void CINumber::decode()
{
    this->number = this->data[0];
    this->number = this->number << 8;
    this->number += this->data[1];
}

/** \brief Metoda zwracajaca CI w postaci numeru.
 *
 * \return unsigned int
 *
 */
unsigned int CINumber::getNumber()
{
    return this->number;
}
