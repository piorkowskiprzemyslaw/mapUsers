#include "Interpreter.h"
#include "Connection.h"

//TODO:
//- w finalnej wersji pouzupelniac consty
//

/**
 * \brief Program mapujacy uzytkownikow do odpowiednich CI
 *
 * \author Przemyslaw Piorkowski  <piorkowskiprzemyslaw@gmail.com>
 *
 */
int main()
{
    std::cout << "Map users to cell in process..." << sizeof(unsigned long) << std::endl;
    Connection * conn;
    Interpreter * interpreter = new Interpreter();
    int dataSize;

    try
    {
        conn = new Connection(4000, 1024);
    }

    catch(SocketException& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }

    /**
     *  Glowna petla programu odpowiedzialna za odbior i przetworzenie danych.
     *  W przyszlosci tutaj rodzial na watki dla kazdego przychodzacego pakietu.
     */
    while(1)
    {
        dataSize = conn->receiveData();
        std::cout << "Rozmiar odebranych danych  " << dataSize << std::endl;
        interpreter->loadBuffer(conn->getBuffer(), dataSize);
        interpreter->interpreteData();
        std::cout << "Version : " << interpreter->getVersion() << std::endl;
        std::cout << "Count   : " << interpreter->getMessagesCounter() << std::endl;
        std::cout << "Length  : " << interpreter->getLength() << std::endl;
        std::cout << "Writing data to file \n" << std::endl;
        interpreter->writeBufferToFile();

    }
    return 0;
}
