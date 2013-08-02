#include "AnonymousMockup.h"

/** \brief Domyslny konstruktor tworzacyanonimowa makiete i oznaczajaca ja timestampem utworzenia.
 *
 * \param mnc unsigned int
 * \param lac unsigned int
 * \param ci unsigned int
 * \param eventid int
 *
 */
AnonymousMockup::AnonymousMockup(unsigned int mnc, unsigned int lac,unsigned int ci, int eventid)
{
    this->timeStamp = this->currTime();
    this->mnc = mnc;
    this->lac = lac;
    this->ci = ci;
    this->eventid = eventid;
}

/** \brief Domyslny konstruktor
 */
AnonymousMockup::~AnonymousMockup() {}

/** \brief Metoda wykorzystywana do tworzenia lancucha zawierajacaego aktulany czas i date.
 *
 * \return std::string
 *
 */
std::string AnonymousMockup::currTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

/** \brief Pobranie mnc z makiety.
 *
 * \return unsigned int
 *
 */
unsigned int AnonymousMockup::getMNC()
{
    return this->mnc;
}

/** \brief Pobranie lac z makiety.
 *
 * \return unsigned int
 *
 */
unsigned int AnonymousMockup::getLAC()
{
    return this->lac;
}

/** \brief Pobranie ci z makiety.
 *
 * \return unsigned int
 *
 */
unsigned int AnonymousMockup::getCI()
{
    return this->ci;
}

/** \brief Pobranie id eventu.
 *
 * \return int
 *
 */
int AnonymousMockup::getEventID()
{
    return this->eventid;
}

/** \brief Pobranie timestampu utworzenia makiety.
 *
 * \return std::string
 *
 */
std::string AnonymousMockup::getTimeStamp()
{
    return this->timeStamp;
}
