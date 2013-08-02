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
    for(std::list<AnonymousMockup *>::iterator it = internalList.begin() ;
        it != internalList.end() ; ++it)
        {
            PrepareSQLStatement statement((*it));
            std::cout << statement.getStatementToExecute()  << std::endl;

        }
}
