// Time.h:  Header-Datei zu Klasse Time

#pragma once

class Date{};

class Time
{
    // friend bool operator== (const Time& lhs, const Time& rhs);

    // friend bool operator== (const Date& lhs, const Date& rhs);  // ???? 
    // ist das sinnvoll

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
    int getHours() const;            // lesender  Zugriff auf 'm_hours'

    int getSeconds() const { return m_seconds; }  // kein großes Geheimnis verraten :)
    void setSeconds(int seconds);

    int getMinutes()  const { return m_minutes; }
    void setMinutes(int minutes);

    // public interface / methods / Unterprogramme
public:
    void reset();       // Schnittstelle eines Unterprogramms
    void increment();   // 
    void print();

    bool equals(const Time& other) const;

    // operators
    bool operator== (const Time& other) const;
};

// ========================================================

// Überflüssig, wenn Zeile 9 (friend-Deklaration) vorhanden ist !
// bool operator== (const Time& t1, const Time& t2);

// Kann ich die equals-Methode überladen ???
bool myEquals(const Time& other);
bool myEquals(const Time& other, const Time& than);
bool myEquals(const Time& other, const Time& than, const Time& whoIs);


// Hier NICHT !!!  Stelligkeit == Anzahl der Operanden: == : 2 
// bool operator== (const Time& t1, const Time& t2, const Time& whoIs);