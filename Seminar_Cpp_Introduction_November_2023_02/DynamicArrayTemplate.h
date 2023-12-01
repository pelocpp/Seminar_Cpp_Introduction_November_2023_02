#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

namespace DynamicArrayTemplate
{
    template <typename T, int TLength = 5>
    class DynamicArray
    {
    private:
        int  m_length;
        T* m_data;

    public:
        // c'tor
        DynamicArray() {
            m_length = TLength;
           //  m_data = nullptr;
            m_data = new T[TLength];
        }

        DynamicArray(int length) {
            m_length = length;
            m_data = new T[m_length];
        }

        // Kopie-Konstruktor
        DynamicArray(const DynamicArray& other) {

            // neuen Puffer anlegen
            m_data = new T[other.m_length];

            // rechten Puffer in linken Puffer umkopieren
            for (int i = 0; i < other.m_length; ++i) {
                m_data[i] = other.m_data[i];
            }

            // aktuelle Länge setzen
            m_length = other.m_length;
        }

        // d'tor
        ~DynamicArray() {

            delete[] m_data;
        }

        // getter
        int getLength() { return m_length; }

        // setter
        // Regelfall: setAt wird mit THROW realisiert

        // FRAGE: T oder T&
        // Ist T elementar: int, double, float: ==> T

        // Ist T NICHT elementar: Klasse (std::string): ==> const T&
        // Unnötige Kopien der Parameter zu vermeiden:

        // Modern C++ // constexpr // C++ 20 concepts

        bool setAt(int index, const T& value) {
            if (index < m_length) {
                m_data[index] = value;
                return true;
            }
            else {
                std::cout << "Falscher Index:" << index << std::endl;
                return false;
            }
        }

        // getter
        T getAt(int index) {
            if (index < m_length) {
                return m_data[index];
            }
            else {
                std::cout << "Falscher Index:" << index << std::endl;

                std::string message

                    = std::string("Falscher Index an Stelle ") + std::to_string(index);

                throw std::out_of_range(message);
            }
        }

        T& operator[] (int index) {

            if (index < m_length) {
                return m_data[index];
            }
            else {
                std::cout << "Falscher Index:" << index << std::endl;

                std::string message

                    = std::string("Falscher Index an Stelle ") + std::to_string(index);

                throw std::out_of_range(message);
            }
        }

        void print() {

            std::cout << "Length: " << m_length << std::endl;
            for (int i = 0; i < m_length; ++i) {
                std::cout << "  " << i << ": " << m_data[i] << std::endl;
            }
        }

        void initialize(T value) {

            for (int i = 0; i < m_length; ++i) {
                m_data[i] = value;
            }
        }

        void resize(int newLength) {

            // allocate new buffer
            T* newBuffer = new T[newLength];

            // Stillschweigend: Nehme an, dass neue Länge größer ist als alte Länge

            // umkopieren
            for (int i = 0; i < m_length; ++i) {
                newBuffer[i] = m_data[i];
            }

            // Rest des neuen Puffers auf 0 vorbelegen
            for (int i = m_length; i < newLength; ++i) {
                newBuffer[i] = T();  // default Konstruktor: geht auch für int, ...
            }

            // noch aktuelle, aber quasi alten Puffer freigeben
            delete[] m_data;

            // Zeiger auf Puffer umsetzen
            m_data = newBuffer;

            // Länge aktualisieren
            m_length = newLength;
        }

        void release()
        {
            delete[] m_data;   // !!!!!!!!!!!!!!!!!!!!!!!!
            m_data = nullptr;  // Muss sein, damit der Konstruktor Bescheid weiß
            m_length = 0;
        }

        // operators
        void operator= (const DynamicArray& other)  // void ist verbesserungsfähig
        {
            // alte linke Seite freigeben
            delete[] m_data;

            // neuen Puffer anlegen
            m_data = new T[other.m_length];

            // rechten Puffer in linken Puffer umkopieren
            for (int i = 0; i < other.m_length; ++i) {
                m_data[i] = other.m_data[i];
            }

            // aktuelle Länge setzen
            m_length = other.m_length;
        }

        // TODO: Rule-of-Three: Kopier-Konstruktor
    };


}
