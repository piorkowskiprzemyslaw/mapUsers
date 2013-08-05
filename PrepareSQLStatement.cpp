#include "PrepareSQLStatement.h"

PrepareSQLStatement::PrepareSQLStatement(AnonymousMockup * mockup)
{
    std::ostringstream ss;
    this->statement.clear();
    this->statement.append("INSERT INTO log VALUES (");
    ss << 1 << " , " << mockup->getLAC() << " , " << mockup->getCI() << " , " << mockup->getEventID() << " , \'" << mockup->getTimeStamp() <<"\'::timestamp)";
    this->statement = this->statement + ss.str();
}

PrepareSQLStatement::~PrepareSQLStatement() {}

std::string PrepareSQLStatement::getStatementToExecute()
{
    return this->statement;
}
