#include "SaveToDatabase.h"

/** \brief konstrutkor.
 *
 * \param internalList std::list<AnonymousMockup*>
 *
 */
SaveToDatabase::SaveToDatabase(std::list<AnonymousMockup*> internalList)
{
    this->internalList = internalList;
}

/** \brief Domyslny destruktor.
 */
SaveToDatabase::~SaveToDatabase()
{
    for(std::list<AnonymousMockup *>::iterator it = this->internalList.begin() ;
        it != this->internalList.end() ; ++it)
        {
            delete((*it));
        }
}

void SaveToDatabase::push()
{
    pqxx::connection c("dbname=anonymousevent user=anonymousDatabase");
    pqxx::work txn(c);
    PrepareSQLStatement prepareSQLStatement;
    std::string statement;

    for(std::list<AnonymousMockup *>::iterator it = internalList.begin() ;
        it != internalList.end() ; ++it)
        {
            prepareSQLStatement.loadMockup(*it);
            statement = prepareSQLStatement.getStatementToExecute();

            try{
                txn.exec(statement.c_str());
            }catch(std::exception e)
            {
                std::cout << e.what() << std::endl;
            }
        }

    std::cout << "Push successfull!" << std::endl;
    txn.commit();
}
