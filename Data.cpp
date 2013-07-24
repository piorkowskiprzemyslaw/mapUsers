#include "Data.h"

/**
 * \brief Domyslny konstruktor
 */
Data::Data(unsigned char * beginOfData,
           int dataLength,
           std::map<FieldName, int>* fieldSizeMap,
           std::map<FieldName, bool>* optionMaskMap)
{
    this->data = beginOfData;
    this->dataLength = dataLength;
    this->fieldSizeMap = *(fieldSizeMap);
    this->optionMaskMap = *(optionMaskMap);
    this->msisdn = NULL;
    this->imsi = NULL;
    this->imei = NULL;
}

/**
 * \brief Domyslny destruktor.
 */
Data::~Data()
{
    if(this->msisdn != NULL)
    {
        delete(this->msisdn);
    }
    std::cout << "3" << std::endl;
    if(this->imsi != NULL)
    {
        delete(this->imsi);
    }
    std::cout << "4" << std::endl;
    if(this->imei != NULL)
    {
        delete(this->imei);
    }
    std::cout << "5" << std::endl;
}

void Data::decode()
{
    int counter = 0;

    if(this->optionMaskMap[MSISDN] == true)
    {
        std::cout << "Dekoduje MSISDN !" << std::endl;
        this->msisdn = new MSISDNumber(this->data , this->fieldSizeMap[MSISDN]);
        this->msisdn->decode();
        counter += this->fieldSizeMap[MSISDN];
    }
    if(this->optionMaskMap[IMSI])
    {
        //creating new IMSINumber object
        counter += this->fieldSizeMap[IMSI];
    }
    if(this->optionMaskMap[IMEI])
    {
        //creating new IMEINumber object
        counter += this->fieldSizeMap[IMEI];
    }

    //dalej zmiana kolejnosci, jak cos to trzeba odkodowywac od tylu  !!
}
