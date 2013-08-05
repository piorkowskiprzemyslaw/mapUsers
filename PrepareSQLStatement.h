#ifndef PREPARESQLSTATEMENT_H
#define PREPARESQLSTATEMENT_H

#include <iostream>
#include <string>
#include <sstream>
#include "AnonymousMockup.h"

class PrepareSQLStatement
{
    private:
        std::string statement;
    public:
        PrepareSQLStatement();
        ~PrepareSQLStatement();
        void loadMockup(AnonymousMockup * mockup);
        std::string getStatementToExecute();
};

#endif // PREPARESQLSTATEMENT_H
