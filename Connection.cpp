#include "Connection.h"

/**
 * \brief Konstruktor ustawnawiajacy nowe "polaczenie" do odbierania ramek udp.
 * \brief Przygotowuje sockety, bufory etc.
 */
Connection::Connection(int port, int bufferLength) throw(SocketException)
{
    /**< tworze socket */
    this->mySocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(this->mySocket == -1)
    {
        throw *(new SocketException("Creating socket issue!"));
    }

    /**< inicjuje strukture sockaddr_in wskazujaca na moj adres */
    memset(&(this->myAddress), '\0', sizeof(this->myAddress));
    this->myAddress.sin_family = AF_INET;
    this->myAddress.sin_port = htons(port);
    this->myAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    this->myAddressLength = sizeof(this->myAddress);

    /**< binduje socket ze struktura */
    if( bind(this->mySocket, (sockaddr *) &(this->myAddress), this->myAddressLength) == -1  )
    {
        throw *(new SocketException("Binding socket exception!"));
    }

    this->bufferLength = bufferLength;
    this->buffer = new unsigned char[this->bufferLength];
    this->lengthOfLastRecivedDataSet = 0;
}

/**
 * \brief Destruktor zamykajacy polaczenie i zwalniajacy przydzielona pamiec.
 */
Connection::~Connection()
{
    delete(this->buffer);
    close(this->mySocket);
}

/**
 * \brief Metoda która odbiera pojedyncza ramke udp i wklada pole 'data' do bufora.
 * \return Warosc zwracana to ilosc zapisanych do bufora bajtów.
 */
int Connection::receiveData()
{
    memset(&(this->otherAddress), 0 , sizeof(this->otherAddress));
    memset(this->buffer, '\0', this->bufferLength);

    this->otherAddressLength = sizeof(this->otherAddress);

    this->lengthOfLastRecivedDataSet = recvfrom(this->mySocket, this->buffer, this->bufferLength,
                0, (sockaddr *) &(this->otherAddress), &this->otherAddressLength);

    return this->lengthOfLastRecivedDataSet;
}

/**
 * \brief Pobranie glebokiej kopii bufora z danymi.
 * \return buffer with data.
 */
unsigned char* Connection::getBuffer()
{
    if(this->lengthOfLastRecivedDataSet == 0)
    {
        return NULL;
    }

    unsigned char * returned = new unsigned char[this->lengthOfLastRecivedDataSet];
    for(int i = 0 ; i < this->lengthOfLastRecivedDataSet ; ++i)
    {
        returned[i] = this->buffer[i];
    }

	return returned;
}
