#include "SocketException.h"

/**
 * \brief Domyslnie stworzenie wyjatku nie opisuje konkretnego bledu.
 */
SocketException::SocketException()
{
    this->msg = "Undefined reason";
}

/**
 * \brief Domyslny dekstruktor...
 */
SocketException::~SocketException() throw() {}

/**
 * \brief Konstruktor z mozliwoscia ustawienia zawartosci wiadomosci.
 * \param msg message about type of exception
 */
SocketException::SocketException(char * msg)
{
    this->msg = msg;
}

/**
 * \brief Pobranie opisu zaistnialego bledu.
 * \return C-type string describing what happened.
 */
const char* SocketException::what() const throw()
{
    return this->msg;
}
