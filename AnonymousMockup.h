#ifndef ANONYMOUSMOCKUP_H
#define ANONYMOUSMOCKUP_H

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>

/** \brief Anonimowa makieta
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class AnonymousMockup
{
    private:
        unsigned int mnc;
        unsigned int lac;
        unsigned int ci;
        int eventid;
        std::string timeStamp;
        std::string currTime();
    public:
        AnonymousMockup(unsigned int mnc, unsigned int lac, unsigned int ci,
                        int eventid);
        ~AnonymousMockup();
        unsigned int getMNC();
        unsigned int getLAC();
        unsigned int getCI();
        int getEventID();
        std::string getTimeStamp();

};

#endif
