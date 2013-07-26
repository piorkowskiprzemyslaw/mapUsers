#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


#include "SocketException.h"

using namespace std;

/**
 * \brief Klasa modelujaca polaczenie majace na celu uzyskanie danych do bufora.
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class Connection
{
    private:
        /**< deskryptor gniazda */
        int mySocket;
        /**< dlugosc bufora danych */
        int bufferLength;
        /**< wskaznik na bufor danych */
        unsigned char * buffer;
        /**< struktura opisujaca adres naszej maszyny */
        sockaddr_in myAddress;
        /**< struktura opisujaca adres maszyny nadawczej */
        sockaddr_in otherAddress;
        /**< dlugosc struktury dla naszej maszyny */
        socklen_t myAddressLength;
        /**< dlugosc struktury dla maszyny nadawczej */
        socklen_t otherAddressLength;

    public:
        Connection(int port, int bufferLength) throw(SocketException);
        ~Connection();
        int receiveData();
        unsigned char * getBuffer();
};

#endif // CONNECTION_H
