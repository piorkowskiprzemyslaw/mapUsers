#ifndef SAVETODATABASE_H
#define SAVETODATABASE_H

#include <iostream>
#include <list>
#include <pqxx/pqxx>
#include <string>
#include <exception>
#include "AnonymousMockup.h"
#include "PrepareSQLStatement.h"

/** \brief Klasa odpowiedzialna za zapisanie przekazanych danych do bazy danych.
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class SaveToDatabase
{
    private:
        std::list<AnonymousMockup *> internalList;
    public:
        SaveToDatabase(std::list<AnonymousMockup *> internalList);
        void push();
        virtual ~SaveToDatabase();
};

#endif // SAVETODATABASE_H
