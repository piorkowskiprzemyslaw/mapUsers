#include "Interpreter.h"
#include "Connection.h"
#include "monitor.h"

Semaphore ileElementow(0), moznaPisac(1);

std::list<std::pair<unsigned char *, int> > sharedBuffer;

void *producent(void *);
void *konsument(void *);

/**
 * \brief Program mapujacy uzytkownikow do odpowiednich CI
 *
 * \author Przemyslaw Piorkowski  <piorkowskiprzemyslaw@gmail.com>
 *
 */
int main()
{
    std::cout << "Map users to cell in process..." << std::endl;
    /*Connection * conn;
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

    while(1)
    {
        dataSize = conn->receiveData();
        std::cout << "Rozmiar odebranych danych  " << dataSize << std::endl;
        interpreter->loadBuffer(conn->getBuffer(), dataSize);
        interpreter->interpreteData();
        std::cout << "Version  : " << interpreter->getVersion() << std::endl;
        std::cout << "Count    : " << interpreter->getMessagesCounter() << std::endl;
        std::cout << "Length   : " << interpreter->getLength() << std::endl;
        std::cout << "Writing data to file \n" << std::endl;
        interpreter->writeBufferToFile();

    }*/

    pthread_t prod , kons;
    int prodRet , konsRet;


    prodRet = pthread_create( &prod, NULL, producent, (void *) NULL);
    konsRet = pthread_create( &kons, NULL, konsument, (void *) NULL);

    pthread_join(prod, NULL);
    pthread_join(kons, NULL);

    return 0;
}


/** \brief Funkcja dla ktorej jest uruchamiany watek producenta
 *
 * \param ptr void*
 * \return void*
 *
 */
void *producent(void * ptr)
{
    Connection * conn;
    unsigned char * pointerToData = NULL;
    int dataSize = 0;

    try
    {
        conn = new Connection(4000,1024);
    } catch (SocketException& e)
    {
        std::cout <<  e.what()  << std::endl;
        return NULL;
    }

    while(1)
    {
        dataSize = conn->receiveData();
        pointerToData = conn->getBuffer();
        if(pointerToData != NULL)
        {
            moznaPisac.p();
            sharedBuffer.push_back(std::make_pair(pointerToData, dataSize));
            ileElementow.v();
            moznaPisac.v();
        }

        dataSize  = 0;
        pointerToData = NULL;
    }

    return NULL;
}


/** \brief Funkcja dla której jest uruchamiany watek konsumenta
 *
 * \param ptr void*
 * \return void*
 *
 */
void *konsument(void * ptr)
{
    Interpreter * interpreter = new Interpreter();
    std::pair<unsigned char  *, int> elementTaken;
    unsigned char * data = NULL;
    int dataLength = 0;

    while(1)
    {
        ileElementow.p();
        moznaPisac.p();

        elementTaken = sharedBuffer.front();
        sharedBuffer.pop_front();

        moznaPisac.v();

        data = elementTaken.first;
        dataLength = elementTaken.second;

        interpreter->loadBuffer(data, dataLength);
        interpreter->interpreteData();
        std::cout << "Version  : " << interpreter->getVersion() << std::endl;
        std::cout << "Count    : " << interpreter->getMessagesCounter() << std::endl;
        std::cout << "Length   : " << interpreter->getLength() << std::endl;
        std::cout << "Writing data to file \n" << std::endl;
        interpreter->writeBufferToFile();

    }

    return NULL;

}
