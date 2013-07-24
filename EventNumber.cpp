#include "EventNumber.h"

/** \brief Domyslny konstruktor, wskazuje na
 *
 * \param data unsigned char*
 * \param dataLength int
 *
 */
EventNumber::EventNumber(unsigned char * data, int dataLength)
{
	this->data = data;
	this->dataLength = dataLength;
	this->number = 0;
}

/** \brief Domyslny konstruktor
 */
EventNumber::~EventNumber() {}

/** \brief Klasa dekodujaca pole Event
 *
 * \return void
 *
 */
void EventNumber::decode()
{
    this->number = int(this->data[0]);
}

/** \brief Pobranie numeru eventu
 *
 * \return unsigned int
 *
 */
int EventNumber::getEventNumber()
{
    return this->number;
}
