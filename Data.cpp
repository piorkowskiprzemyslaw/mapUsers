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
    if(this->imsi   != NULL)    delete(this->imsi);
    if(this->imei   != NULL)    delete(this->imei);
    if(this->lai    != NULL)    delete(this->lai);
    if(this->ci     != NULL)    delete(this->ci);
    if(this->rai    != NULL)    delete(this->rai);
    if(this->vmsc   != NULL)    delete(this->vmsc);
    if(this->sgsn   != NULL)    delete(this->sgsn);
    if(this->event  != NULL)    delete(this->event);
}

void Data::decode()
{
    unsigned int counter = 0;
    unsigned int reverseCounter = 0;

    if(this->optionMaskMap[MSISDN] == true)
    {
        this->msisdn = new MSISDNumber(&(this->data[counter]) , this->fieldSizeMap[MSISDN]);
        this->msisdn->decode();
        std::cout << "MSISDN : " << this->msisdn->getAsNumber() << std::endl;
        counter += this->fieldSizeMap[MSISDN];
    }
    if(this->optionMaskMap[IMSI] == true)
    {
        this->imsi = new IMSINumber(&(this->data[counter]), this->fieldSizeMap[IMSI]);
        this->imsi->decode();
        std::cout << "IMSI   : " << this->imsi->getAsNumber() << std::endl;
        counter += this->fieldSizeMap[IMSI];
    }
    if(this->optionMaskMap[IMEI] == true)
    {
        this->imei = new IMEINumber(&(this->data[counter]), this->fieldSizeMap[IMEI]);
        this->imei->decode();
        std::cout << "IMEI   : " << this->imei->getAsNumber() << std::endl;
        counter += this->fieldSizeMap[IMEI];
    }
    /*****************  TERAZ ROZKODOWYWANIE OD KONCA *************************/
    if(this->optionMaskMap[EVENT] == true)
    {
        reverseCounter += this->fieldSizeMap[EVENT];
        this->event = new EventNumber(&(this->data[this->dataLength - reverseCounter]), this->fieldSizeMap[EVENT]);
        this->event->decode();
        std::cout << "EVENT  : " << this->event->getEventNumber() << std::endl;
    }
    if(this->optionMaskMap[SGSN] == true)
    {
        reverseCounter += this->fieldSizeMap[SGSN];
        this->sgsn = new SGSNumber(&(this->data[this->dataLength - reverseCounter]), this->fieldSizeMap[SGSN]);
        this->sgsn->decode();
        std::cout << "SGSN   : " << this->sgsn->getAsNumber() << std::endl;
    }
    if(this->optionMaskMap[VMSC] == true)
    {
        reverseCounter += this->fieldSizeMap[VMSC];
        this->vmsc = new VMSCNumber(&(this->data[this->dataLength - reverseCounter]),this->fieldSizeMap[VMSC]);
        this->vmsc->decode();
        std::cout << "VMSC   : " << this->vmsc->getAsNumber() << std::endl;
    }
    if(this->optionMaskMap[RAI] == true)
    {
        //tego poki co nie rozkodowuje.
        reverseCounter += this->fieldSizeMap[RAI];
    }
    if(this->optionMaskMap[CI] == true)
    {
        reverseCounter += this->fieldSizeMap[CI];
        this->ci = new CINumber(&(this->data[this->dataLength - reverseCounter]),this->fieldSizeMap[CI]);
        this->ci->decode();
        std::cout << "CI     : " << this->ci->getNumber() << std::endl;
    }
    if(this->optionMaskMap[LAI] == true)
    {
        reverseCounter += this->fieldSizeMap[LAI];
        this->lai = new LAINumber(&(this->data[this->dataLength - reverseCounter]),this->fieldSizeMap[LAI]);
        this->lai->decode();
        std::cout << "LAC    : " << this->lai->getLAC() << std::endl;
        std::cout << "MNC    : " << this->lai->getMNCNumber() << std::endl;
    }

    if((counter + reverseCounter) > dataLength)
    {
        std::cout  << "FATAL ERROR" << std::endl;
    }
}

/** \brief Pobiera dlugosc tego pola data
 *
 * \return unsigned int
 *
 */
unsigned int Data::getDataLength()
{
    return this->dataLength;
}
