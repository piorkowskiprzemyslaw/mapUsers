#include "MSISDNumber.h"

MSISDNumber::MSISDNumber(unsigned char * data, int dataLength)
{
    this->data = data;
    this->dataLength = dataLength;
}

MSISDNumber::~MSISDNumber() {}

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
