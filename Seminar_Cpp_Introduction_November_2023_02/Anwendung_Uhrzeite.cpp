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


void uhrzeiten_03()
{
    Time jetzt (13, 17, 11);

    Time dann(14, 30, 40);

    bool gleich = jetzt.equals(dann);

    if (jetzt == dann) {                              // Infix-Notation
        std::cout << "sind gleich" << std::endl;
    }
    else {
        std::cout << "sind nicht gleich" << std::endl;
    }

    if (jetzt == dann) {                              // Infix-Notation
        std::cout << "sind gleich" << std::endl;
    }
    else {
        std::cout << "sind nicht gleich" << std::endl;
    }

    // Nur als Spielerei :-)

    if ( jetzt.operator== (dann) ) {
        std::cout << "sind gleich" << std::endl;
    }
    else {
        std::cout << "sind nicht gleich" << std::endl;
    }

    // Nur als Spielerei :-)

    //if ( operator== (jetzt, dann)   ) {
    //    std::cout << "sind gleich" << std::endl;
    //}
    //else {
    //    std::cout << "sind nicht gleich" << std::endl;
    //}
}