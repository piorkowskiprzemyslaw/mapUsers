#include "PrepareSQLStatement.h"

/** \brief Konstruktor przymujacy transakce.
 *
 * \param cellID pqxx::work*
 *
 */
PrepareSQLStatement::PrepareSQLStatement(pqxx::work * cellID)
{
    this->cellID = cellID;
}

/** \brief Domyslny destruktor.
 */
PrepareSQLStatement::~PrepareSQLStatement() {}

/** \brief Pobranie polecenia.
 *
 * \return std::string
 *
 */
std::string PrepareSQLStatement::getStatementToExecute()
{
    return this->statement;
}

/** \brief Zaladowanie nowej makiety i wygenerowanie odpowiedniego polecenia SQL
 *
 * \param mockup AnonymousMockup*
 * \return void
 *
 */
void PrepareSQLStatement::loadMockup(AnonymousMockup * mockup)
{
    std::ostringstream ss;
    std::string lac;
    std::string ci;
    ss << mockup->getLAC();
    lac = ss.str();
    ss.clear();
    ss.str("");
    ss << mockup->getCI();
    ci = ss.str();
    ss.clear();
    ss.str("");

    pqxx::result coordinates =
            this->cellID->exec("SELECT x,y,r "
                               "FROM info  "
                               "WHERE lac= " + lac+
                               "AND "
                               "ci = " + ci );

    ss.str("");
    ss.clear();

    this->statement.clear();
    this->statement.append("INSERT INTO log VALUES (");
    ss << "nextval(\'id\') , " << mockup->getLAC() << " , " << mockup->getCI();
    ss << " , " << mockup->getEventID() << " , \'";
    ss << mockup->getTimeStamp() <<"\'::timestamp ";

    /**< Moze zdarzyc sie ze cellki nie ma w bazie */
    if(coordinates.size() == 0)
    {
        ss << ")";
        this->statement = this->statement + ss.str();
    }else
    {
        ss << ",  \'<(";
        ss << coordinates[0]["x"].as<std::string>() << " , ";
        ss << coordinates[0]["y"].as<std::string>() << " ) , ";
        ss << coordinates[0]["r"].as<std::string>() << " >\'::circle )";
        this->statement = this->statement + ss.str();
    }
}
