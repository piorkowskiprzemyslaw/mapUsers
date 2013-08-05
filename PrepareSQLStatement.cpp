#include "PrepareSQLStatement.h"

PrepareSQLStatement::PrepareSQLStatement() {}

PrepareSQLStatement::~PrepareSQLStatement() {}

std::string PrepareSQLStatement::getStatementToExecute()
{
    return this->statement;
}

void PrepareSQLStatement::loadMockup(AnonymousMockup * mockup)
{
    std::ostringstream ss;
    this->statement.clear();
    this->statement.append("INSERT INTO log VALUES (");
    ss << "nextval(\'id\') , " << mockup->getLAC() << " , " << mockup->getCI() << " , " << mockup->getEventID() << " , \'" << mockup->getTimeStamp() <<"\'::timestamp)";
    this->statement = this->statement + ss.str();
}
