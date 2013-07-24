#include "MSISDNumber.h"

/**
 * \brief Konstruktor ustawia data i dataLength. Nie kopiuje danych.
 */
MSISDNumber::MSISDNumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
}

/**
 * \brief Destruktor nie musi nic robic, bo nie byla przydzielna pamiec w konstruktorze.
 */
MSISDNumber::~MSISDNumber() {}

/**
 * \brief Dekodowanie pola danych do sensownego numeru.
 */
void MSISDNumber::decode()
{
    this->extensionByte = this->data[0];

    for(int i = 1 ; i < this->dataLength ; ++i)
    {
        std::pair<int, int> decodedPair = Helper::TBCDByteEncode(this->data[i]);

        if(decodedPair.first == 15)
        {
            return;
        } else {
            this->number.push_back(decodedPair.first);
        }

        if(decodedPair.second == 15)
        {
            return;
        } else {
            this->number.push_back(decodedPair.second);
        }

        //Zakomentowana wersja jest wydajniejsza, ale mniej czytelna, jak co to urzywac wlasnie tej wersji...
        /*
        if(decodedPair.second == 15)
        {
            if(decodedPair.first == 15)
            {
                return;
            }

            this->number.push_back(decodedPair.first);

        } else {

            this->number.push_back(decodedPair.first);
            this->number.push_back(decodedPair.second);
        }
        */
    }
}

/**
 * \brief Funkcja testowa sprawdzajaca poprawnosc dekodowania poprzez zapis do pliku.
 */
void MSISDNumber::writeNumber()
{
    for(std::list<unsigned char>::iterator it = this->number.begin() ;
        it != this->number.end() ; ++it)
    {
        std::cout << int(*it) << " ";
    }
    std::cout << '\n';
}

/**
 * \brief Zwraca numer w postaci listy powiazanej unsigned charow
 * \return std::list<unsigned char>
 */
std::list<unsigned char> MSISDNumber::getNumberAsList()
{
    return this->number;
}

/**
 * \brief Zwracaa numer w postaci liczby unsigned long
 * \return unsigned long
 */
unsigned long MSISDNumber::getNumberAsNumber()
{
    unsigned long returned;
    int i = 0;

    for(std::list<unsigned char>::iterator it = this->number.begin() ; it != this->number.end() ; ++it, ++i)
    {
        returned += ((unsigned long)(*it)) * pow(10.0, (double)(this->number.size()-1-i));
    }

    return returned;
}

/**
 * \brief Pobriera extension byte numeru pola MSISDN
 * \return unsigned char
 */
unsigned char MSISDNumber::getExtensionByte()
{
    return this->extensionByte;
}
