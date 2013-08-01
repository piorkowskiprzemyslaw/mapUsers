#include "AnonymousMockup.h"

AnonymousMockup::AnonymousMockup(unsigned int mnc, unsigned int lac,
                                 unsigned int ci, int eventid)
{
    this->timeStamp = this->currTime();
    this->mnc = mnc;
    this->lac = lac;
    this->ci = ci;
    this->eventid = eventid;
}

AnonymousMockup::~AnonymousMockup() {}

std::string AnonymousMockup::currTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

unsigned int AnonymousMockup::getMNC()
{
    return this->mnc;
}

unsigned int AnonymousMockup::getLAC()
{
    return this->lac;
}

unsigned int AnonymousMockup::getCI()
{
    return this->ci;
}

int AnonymousMockup::getEventID()
{
    return this->eventid;
}

std::string AnonymousMockup::getTimeStamp()
{
    return this->timeStamp;
}
