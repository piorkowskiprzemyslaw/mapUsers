#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <fstream>
#include <map>
#include <netinet/in.h>
#include "FieldName.h"
#include "OptionMask.h"
#include "Data.h"

/**
 *  \brief Klasa interpretujaca otrzymany  bufor z danymi wedlug standardu opisanego
 *  \brief w dokomencie Feature 1726: Subscriber Data Feed from VLR.
 *
 *  \author Przemyslaw Piorkowski <piorkowskiprzemyslaw@gmail.com>
 */
class Interpreter
{
    private:
        /**< aktualny bufor do interpretacji */
        unsigned char * buffer;
        /**< dlugosc bufora */
        int bufferLength;
        /**< wartosc pola 'version' */
        unsigned char  version;
        /**< wartosc pola 'count' */
        unsigned char messagesCounter;
        /**< tablica wielkosc w bajtach poszczegolnych odkodowywawnych pol */
        std::map<FieldName, int> fieldSizeMap;
        /**< tablica option mask */
        std::map<FieldName, bool> optionMaskMap;
        /**< zmienna reprezentujaca pole option mask */
        OptionMask* optionMask;
        /**< wartosc pola 'length' */
        unsigned char length;
        /**< Pole data z ramki udp */
        Data * data;

    public:
        Interpreter();
        ~Interpreter();
        void loadBuffer(unsigned char * buffer, int bufferLength);
        void interpreteData();
        int getVersion();
        int getMessagesCounter();
        int getLength();
        void writeBufferToFile();

};

#endif // INTERPRETER_H
