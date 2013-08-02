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
        PrepareSQLStatement(AnonymousMockup * mockup);
        ~PrepareSQLStatement();
        std::string getStatementToExecute();
};

#endif // PREPARESQLSTATEMENT_H
