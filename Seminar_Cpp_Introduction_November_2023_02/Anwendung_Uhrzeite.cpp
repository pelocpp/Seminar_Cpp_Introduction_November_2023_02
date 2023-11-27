#include "Time.h"

#include <string>
#include <iostream>

void uhrzeiten()
{
    Time jetzt;

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