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
    this->lai = NULL;
    this->ci = NULL;
    this->rai = NULL;
    this->vmsc = NULL;
    this->sgsn = NULL;
    this->event = NULL;
}

/**
 * \brief Domyslny destruktor.
 */
Data::~Data()
{
    if(this->msisdn != NULL)    delete(this->msisdn);
    if(this->imsi != NULL)      delete(this->imsi);
    if(this->imei != NULL)      delete(this->imei);
    if(this->lai  != NULL)      delete(this->lai);
    if(this->ci != NULL)        delete(this->ci);
    if(this->rai != NULL)       delete(this->rai);
    if(this->vmsc != NULL)      delete(this->vmsc);
    if(this->sgsn != NULL)      delete(this->sgsn);
    if(this->event != NULL)     delete(this->event);
}

void Data::decode()
{
    int counter = 0;

    if(this->optionMaskMap[MSISDN] == true)
    {
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
