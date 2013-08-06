#include "SaveToDatabase.h"

/** \brief konstrutkor.
 *
 * \param internalList std::list<AnonymousMockup*>
 *
 */
SaveToDatabase::SaveToDatabase(std::list<AnonymousMockup*> internalList)
{
    this->internalList  =   internalList;
    this->anonymousConn =   new pqxx::connection("dbname=anonymousevent user=anonymousDatabase");
    this->anonymous     =   new pqxx::work(*this->anonymousConn);
    this->cellIDConn    =   new pqxx::connection("dbname=cellid user=cellid");
    this->cellID        =   new pqxx::work(*this->cellIDConn);
}

/** \brief Domyslny destruktor.
 */
SaveToDatabase::~SaveToDatabase()
{
    delete(this->anonymous);
    this->anonymousConn->disconnect();
    delete(this->anonymousConn);
    delete(this->cellID);
    this->cellIDConn->disconnect();
    delete(this->cellIDConn);

    for(std::list<AnonymousMockup *>::iterator it = this->internalList.begin() ;
        it != this->internalList.end() ; ++it)
        {
            delete((*it));
        }
}

/** \brief Zapisanie do bazy danych makiet oderanych z bufora.
 *
 * \return void
 */
void SaveToDatabase::push()
{
    PrepareSQLStatement prepareSQLStatement(this->cellID);
    std::string statement;

    for(std::list<AnonymousMockup *>::iterator it = internalList.begin() ;
        it != internalList.end() ; ++it)
        {
            prepareSQLStatement.loadMockup(*it);
            statement = prepareSQLStatement.getStatementToExecute();

            try{
                this->anonymous->exec(statement.c_str());
            }catch(std::exception e)
            {
                std::cout << e.what() << std::endl;
            }
        }

    this->anonymous->commit();
}
