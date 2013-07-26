#include "Interpreter.h"

/**
* \brief Domyslny konstruktor, inicjuje mapy.
*/
Interpreter::Interpreter()
{
    fieldSizeMap.insert(std::pair<FieldName, int>(MSISDN, 9));
    fieldSizeMap.insert(std::pair<FieldName, int>(IMSI, 8));
    fieldSizeMap.insert(std::pair<FieldName, int>(IMEI, 8));
    fieldSizeMap.insert(std::pair<FieldName, int>(RSV1, -1));
    fieldSizeMap.insert(std::pair<FieldName, int>(RSV2, -1));
    fieldSizeMap.insert(std::pair<FieldName, int>(RSV3, -1));
    fieldSizeMap.insert(std::pair<FieldName, int>(RSV4, -1));
    fieldSizeMap.insert(std::pair<FieldName, int>(RSV5, -1));
    fieldSizeMap.insert(std::pair<FieldName, int>(RSV6, -1));
    fieldSizeMap.insert(std::pair<FieldName, int>(SAI, 0));
    fieldSizeMap.insert(std::pair<FieldName, int>(LAI, 5));
    fieldSizeMap.insert(std::pair<FieldName, int>(CI, 2));
    fieldSizeMap.insert(std::pair<FieldName, int>(RAI, 1));
    fieldSizeMap.insert(std::pair<FieldName, int>(VMSC, 9));
    fieldSizeMap.insert(std::pair<FieldName, int>(SGSN, 9));
    fieldSizeMap.insert(std::pair<FieldName, int>(EVENT, 1));

}

/**
* \brief Domyslny destruktor, zwalnia bufor.
*/
Interpreter::~Interpreter()
{
    if(this->buffer != NULL)
    {
        delete(this->buffer);
    }
}

/**
* \brief Metoda za pomoca ktorej usuwamy stary bufor i ladujemy nowy.
*
* \param buffer C-style chain of data
* \param bufferLength size of buffer
*
*/
void Interpreter::loadBuffer(unsigned char * bufferIn,int bufferLengthIn)
{
    if(this->buffer != NULL)
    {
        delete(this->buffer);
    }

    this->buffer = new unsigned char[bufferLengthIn];
    this->bufferLength = bufferLengthIn;
    for(int i = 0 ; i < bufferLengthIn ; ++i)
    {
        this->buffer[i] = bufferIn[i];
    }
}

/**
* \brief Interpreteowawnie danych z bufora.
*
* Jesli bufor pusty, albo dane nie maja sensu wszystkie
* wartosci pol danych sa ustawiane na domyslne wartosci.
*/
void Interpreter::interpreteData()
{
    if(this->buffer == NULL)
    {
        return;
    }

    unsigned int counter = 0;

    this->version = this->buffer[counter];
    this->messagesCounter = this->buffer[++counter];

    for(int i = 0 ; i < this->messagesCounter ; ++i)
    {
            this->optionMask = new OptionMask(this->buffer[++counter], this->buffer[++counter]);
            this->optionMask->decodeOptionMask();
            this->optionMaskMap = *(this->optionMask->getOptionMaskMap());

            this->length = this->buffer[++counter];

            this->data = new Data(&(this->buffer[counter+1]), this->getLength(), &(this->fieldSizeMap), &(this->optionMaskMap));
            this->data->decode();

            counter += this->length;

            delete(this->optionMask);
            delete(this->data);
    }
}

/**
* \brief Pobranie pola 'version' z analizowanego bufora.
*/
int Interpreter::getVersion()
{
    return this->version;
}

/**
* \brief Pobranie pola 'counter' z analizowanego bufora.
*/
int Interpreter::getMessagesCounter()
{
    return this->messagesCounter;
}

/**
* \brief Zapisanie bufora do pliku w postaci szesnastkowej
* Ma na celu weryfikowanie poprawnosci przetwawrzanych danych
*/
void Interpreter::writeBufferToFile()
{
    std::ofstream writeToFile;
    writeToFile.open("TroubleShooting", std::fstream::out | std::fstream ::app);
    writeToFile << std::hex ;
    for(int i = 0 ; i < this->bufferLength ; ++i)
    {
        writeToFile << int(this->buffer[i]) << " ";
    }
    writeToFile << '\n';
    writeToFile.close();
}

/**
* \brief Pobranie warosci pola 'length'
*/
int Interpreter::getLength()
{
    return this->length;
}
