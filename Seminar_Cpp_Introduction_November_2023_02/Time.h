// Time.h:  Header-Datei zu Klasse Time

#pragma once

class Time
{
private:
    // member data / instance variables
    int m_seconds;
    int m_minutes;
    int m_hours;

    int m_msecs;


    void setMillisekunden(int msecs);

public:
    // Konstruktoren // c'tors 
    Time();

    // Time(int hours, int seconds = 2, int minutes = 1);
    Time(int hours, int seconds, int minutes);


    //getter/setter
    void setHours(int hours);  // schreibender Zugriff auf 'm_hours'
    int getHours();            // lesender  Zugriff auf 'm_hours'

    int getSeconds() { return m_seconds; }  // kein groﬂes Geheimnis verraten :)
    void setSeconds(int seconds);

    int getMinutes() { return m_minutes; }
    void setMinutes(int minutes);



    // public interface / methods / Unterprogramme
public:
    void reset();       // Schnittstelle eines Unterprogramms
    void increment();   // 
    void print();
};


