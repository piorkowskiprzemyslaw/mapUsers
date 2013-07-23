#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <map>
#include <utility>

//field classes here
#include "FieldName.h"
#include "MSISDNumber.h"
#include "IMSINumber.h"
#include "IMEINumber.h"
#include "LAINumber.h"
#include "CINumber.h"
#include "RAINumber.h"
#include "VMSCNumber.h"
#include "SGSNumber.h"
#include "EventNumber.h"

/**
 * \brief Reprezentacja pola data z ramki  UDP i rozkodowywawnie znaczenia poszczegolnych skladnikow.
 *
 * \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class Data
{
    private:
        /**< Mapa niezbedna do okreslenia rozmiarow poszczegolnych pol */
        std::map<FieldName, int> fieldSizeMap;
        /**< Mapa do ze zdekodowana maska */
        std::map<FieldName, bool> optionMaskMap;
        /**< Blok pamieci w ktorym sa dane */
        unsigned char * data;
        /**< Dlugosc bloku pamieci z danymi */
        int dataLength;
        /**< pole MSISDN */
        MSISDNumber* msisdn;
        /**< pole IMSI */
        IMSINumber* imsi;
        /**< pole IMEI */
        IMEINumber* imei;
        /**< pole LAI */
        LAINumber* lai;
        /**< pole CI */
        CINumber* ci;
        /**< pole RAI */
        RAINumber* rai;
        /**< pole VMSC */
        VMSCNumber* vmsc;
        /**< pole SGSN */
        SGSNumber* sgsn;
        /**< pole EVENT */
        EventNumber* event;
    public:
        Data(unsigned char * beginOfData,
             int dataLength,
             std::map<FieldName, int>* fieldSizeMap,
             std::map<FieldName, bool>* optionMapMask);
        ~Data();
        void decode();

};

#endif // DATA_H
