// Time.h:  Implementierungs-Datei zu Klasse Time

#include <cstdio>
#include <iostream>

#include "Time.h"    // <============== textuelle Ersetzung


void Time::setMillisekunden(int msecs)
{
    // int m_tmp;

    this->m_msecs = msecs;

    // oder kürzer

    m_msecs = msecs;

    // OO: Paar: an welchem Objekt welche Variable / Methode
    getHours();
}



Time::Time() : m_hours (0), m_minutes(0), m_seconds(0), m_msecs(0) {}

// oder

// constructor chaining - damit erspare ich Wiederholungen
// Time::Time() : Time (0, 0, 0) {}

// oder

//Time::Time()
//{
//    m_hours = 0;
//    m_minutes = 0;
//    m_seconds = 0;
//}


// ------------------------------------------------------

Time::Time(int hours, int minutes, int seconds)
{
    //m_hours = hours;
    //m_minutes = seconds;
    //m_seconds = minutes;

    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}


void Time::setHours(int hours)
{
    // Plausibilität des Parameters überprüfen muss !!!
    if (hours < 0 || hours >= 24) {

        std::printf("Falsche Anzahl fuer Stunden: %d\n", hours);

        // ???????????????????????
        // was machen wir in diesem Fall mit m_hours
        m_hours = 0;
    }
    else
    {
        m_hours = hours;
    }
}

void Time::setMinutes(int minutes)
{
    if (0 <= minutes && minutes < 60) {
        m_minutes = minutes;
    }
    else {
        // we don't modify the current value of 'm_minutes'
        std::cout << "Wrong value for minutes: " << minutes << std::endl;
        m_minutes = 0;
    }
}

void Time::setSeconds(int seconds)
{
    if (0 <= seconds && seconds < 60) {
        m_seconds = seconds;
    }
    else {
        // we don't modify the current value of 'm_seconds'
        std::cout << "Wrong value for seconds: " << seconds << std::endl;
        m_seconds = 0;
    }
}



int Time::getHours()
{
    return m_hours;
}


void Time::reset()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

void Time::print()
{
    // C:
    std::printf( "%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
}

void Time::increment()
{
    // very, very simple // Überlauf fehlt
    m_seconds = m_seconds + 1;
}