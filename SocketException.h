#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <string>
#include <exception>

/**
 * \brief Klasa reprezentujšca wyjštki podczas tworzenia nowego socketa
 * \brief przechowuje jedynie tekstowa reprezentacje bledu.
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */

class SocketException : public std::exception
{
    private:
        /**< wiadomosc tekstowa zostawiana podczas generowania wyjatku */
        char * msg;
    public:
        SocketException();
        SocketException(char * msg);
        ~SocketException() throw();
        virtual const char * what() const throw();
};

#endif // SOCKETEXCEPTION_H
