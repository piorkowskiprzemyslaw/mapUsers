#ifndef PREPARESQLSTATEMENT_H
#define PREPARESQLSTATEMENT_H

#include <iostream>
#include <string>
#include <sstream>
#include <pqxx/pqxx>
#include "AnonymousMockup.h"

/** \brief Klasa przygotowujaca polecenie do wykonania przez baze danych.
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class PrepareSQLStatement
{
    private:
        /**< Przygotowawne polecenie */
        std::string statement;
        /**< Transakcja do  pytania o wspolrzedne dla cell id */
        pqxx::work* cellID;
    public:
        PrepareSQLStatement( pqxx::work* cellID);
        ~PrepareSQLStatement();
        void loadMockup(AnonymousMockup * mockup);
        std::string getStatementToExecute();
};

#endif // PREPARESQLSTATEMENT_H
