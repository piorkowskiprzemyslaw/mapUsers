#include "Interpreter.h"
#include "Connection.h"
#include "Semaphore.h"
#include "AnonymousMockup.h"
#include "SaveToDatabase.h"

Semaphore ileElementow(0), moznaPisac(1);

Semaphore moznaPobierac(0), moznaZapisywac(1);

std::list<std::pair<unsigned char *, int> > sharedBuffer;
std::list<AnonymousMockup *> sendToDatabase;

void *producent(void *);
void *konsument(void *);
void *zapisujacy(void *);

/**
 * \brief Program mapujacy uzytkownikow do odpowiednich CI
 *
 * \author Przemyslaw Piorkowski  <piorkowskiprzemyslaw@gmail.com>
 *
 */
int main()
{
    std::cout << "Map users to cell in process..." << std::endl;

    pthread_t prod , kons , zapis;
    int prodRet , konsRet, zapisRet;

    prodRet = pthread_create( &prod, NULL, producent, (void *) NULL);
    konsRet = pthread_create( &kons, NULL, konsument, (void *) NULL);
    zapisRet = pthread_create( &zapis, NULL, zapisujacy, (void *) NULL);

    pthread_join(prod, NULL);
    pthread_join(kons, NULL);
    pthread_join(zapis, NULL);

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
    std::list<AnonymousMockup *> lista;
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
        lista = interpreter->getDecodedData();

        moznaZapisywac.p();

        for(std::list<AnonymousMockup *>::iterator it = lista.begin() ; it != lista.end() ; ++it)
        {
            sendToDatabase.push_back(*it);
        }
        /**< Buforowawnie minimalnej ilosci do insertowania w bazie danych */
        if(sendToDatabase.size() > 3)
        {
            moznaPobierac.v();
        }

        moznaZapisywac.v();

        interpreter->writeBufferToFile();
    }
    return NULL;
}

/** \brief Funkcja dla ktorej uruchamiany jest watek buforujacy i zapisujacy do bazy danych
 *
 * \param ptr void*
 * \return void*
 *
 */
void *zapisujacy(void * ptr)
{
    std::list<AnonymousMockup *> internalList;
    AnonymousMockup * anonymousMockup;

    while(1)
    {
        moznaPobierac.p();
        moznaZapisywac.p();

        while(sendToDatabase.size() > 0 )
        {
            anonymousMockup = sendToDatabase.front();
            sendToDatabase.pop_front();
            internalList.push_back(anonymousMockup);
        }

        moznaZapisywac.v();

        SaveToDatabase saveToDatabase(internalList);
        saveToDatabase.push();

        internalList.clear();
    }
    return NULL;
}
