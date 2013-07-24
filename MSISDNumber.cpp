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
                std::cout << "zdekodowawano!" << std::endl;
                this->writeNumber();
            return;
        } else {
            this->number.push_back(decodedPair.first);
        }

        if(decodedPair.second == 15)
        {
                std::cout << "zdekodowawano!" << std::endl;
                this->writeNumber();
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
