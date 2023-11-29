#include <iostream>

class DynamicArray
{
private:
    int  m_length;
    int* m_data;   // int m_data[m_length];  das geht eben nicht 

public:
    // c'tor
    DynamicArray() {
        m_length = 0;
        m_data = nullptr;
    }

    DynamicArray(int length) {
        m_length = length;
        m_data = new int[m_length];
    }

    // Kopie-Konstruktor
    DynamicArray(const DynamicArray& other) {
        // flat copy: WRONG
        // m_length = other.m_length;
        // m_data = other.m_data;

        // neuen Puffer anlegen
        m_data = new int[other.m_length];

        // rechten Puffer in linken Puffer umkopieren
        for (int i = 0; i < other.m_length; ++i) {
            m_data[i] = other.m_data[i];
        }

        // aktuelle Länge setzen
        m_length = other.m_length;
    }


    // d'tor
    ~DynamicArray() {

        delete[] m_data;   // !!!!!!!!!!!!!!!!!!!!!!!!
    }

    // getter
    int getLength() { return m_length; }

    // setter
    bool setAt(int index, int value) {
        if (index < m_length) {
            m_data[index] = value;
            return true;
        }
        else {
            std::cout << "Falscher Index:" << index << std::endl;
            return false;
        }
    }

    void print() {

        std::cout << "Length: " << m_length << std::endl;
        for (int i = 0; i < m_length; ++i) {
            std::cout << "  " << i << ": " << m_data[i] << std::endl;
        }
    }

    void initialize(int value) {

        for (int i = 0; i < m_length; ++i) {
            m_data[i] = value;
        }
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
        m_data = new int[other.m_length];

        // rechten Puffer in linken Puffer umkopieren
        for (int i = 0; i < other.m_length; ++i) {
            m_data[i] = other.m_data[i];
        }

        // aktuelle Länge setzen
        m_length = other.m_length;
    }
};

void test_dynamic_array_01()
{
    int currentLength;

    std::cout << "Length: ";
    std::cin >> currentLength; 

    DynamicArray dynArray(currentLength);   // Konstruktor
    dynArray.print();

    // möchte die Länge abfragen
    int wieLang = dynArray.getLength();
    std::cout << "Length: " << wieLang << std::endl;

    dynArray.initialize(123);
    dynArray.print();

    // Element an der Stelle 5 mit dem Wert 10 belegen:
    dynArray.setAt(3, 10);
    dynArray.print();

    dynArray.release();
    dynArray.print();
}

DynamicArray dynamicArrayHelper()
{
    // DynamicArray zusammenstellen
    DynamicArray dynArray(5);
    dynArray.initialize(123);
    dynArray.print();

    return dynArray;
}

void test_dynamic_array_02()
{
    DynamicArray da(5);
    da.initialize(123);
    da.print();

    DynamicArray daCopy (10);
    daCopy = da;   // Überladen von Operatoren: operator =

    da.print();
    daCopy.print();
}

void test_dynamic_array_03()
{
    DynamicArray da(5);
    da.initialize(123);
    da.print();

    DynamicArray daCopy (da);  // Kopie

    da.print();
    daCopy.print();
}

void test_dynamic_array()
{
    test_dynamic_array_03();
    std::cout << "Done." << std::endl;
}