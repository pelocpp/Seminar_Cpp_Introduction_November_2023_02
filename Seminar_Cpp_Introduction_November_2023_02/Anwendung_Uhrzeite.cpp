#include "Time.h"

#include <string>
#include <iostream>

void uhrzeiten()
{
    Time jetzt;   // Funktion namens 'jetzt' ohne Parameter mit Time als Ergebnistyp

    // jetzt.m_hours = 11;

    // jetzt.m_hours = 11;
    jetzt.setHours(12);
    jetzt.setMinutes(23);
    jetzt.setSeconds(10);

    jetzt.print();   // Paar: Welches Objekt // welcher Member

    Time spaeter;
    spaeter.setHours(14);
    spaeter.setMinutes(100);
    spaeter.setSeconds(12);

    spaeter.print();

    int wievieleMinuten = jetzt.getMinutes();
    std::cout << "wievieleMinuten: " << wievieleMinuten << std::endl;

    // std::string s("ABC");
}

void uhrzeiten_02()
{
    Time leer;

    // Fluent Programming Style : Named parameters 
    Time jetzt (14, 33, 10);   // 13, 33, 10 // spezielle Methode
    jetzt.print();

    //Time wann(15, 30);
    //wann.print();

    //Time wannAuch (16);
    //wannAuch.print();
}
