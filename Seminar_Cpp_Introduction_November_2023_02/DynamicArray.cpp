#include <iostream>
#include <stdexcept>
#include <string>

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

    // getter
    int getAt(int index) {
        if (index < m_length) {
            return m_data[index];
        }
        else {
            std::cout << "Falscher Index:" << index << std::endl;
            return -1; // ???????????????????  NEIN
        }
    }

    // operator 
    //int operator[] (int index) {
    //    if (index < m_length) {
    //        return m_data[index];
    //    }
    //    else {
    //        std::cout << "Falscher Index:" << index << std::endl;
    //        return -1; // ???????????????????  NEIN
    //    }
    //}

    int& operator[] (int index) {

        static int empty = -1;

        if (index < m_length) {
            return m_data[index];
        }
        else {
            std::cout << "Falscher Index:" << index << std::endl;
            
            // Lösung 1:
            // return empty;  // Unschön, weil der Aufrufer nicht so wirklich
            //                // mitbekommt, dass der Index falsch ist.

            // Lösung 2:
            //                    "..."  const char*
            // std::string message = "Falscher Index an Stelle" + index;

            std::string message1 = "Falscher Index an Stelle " + std::to_string(index);

            std::string message2 
                = std::string ("Falscher Index an Stelle ") + std::to_string (index);

            //std::string message3
            //    = std::string("Falscher Index an Stelle ").append(std::to_string(index));

            throw std::out_of_range(message1);
        }
    }

    // int* operator[] (int index) {

    //    static int empty = -1;

    //    if (index < m_length) {
    //        return &m_data[index];
    //    }
    //    else {
    //        std::cout << "Falscher Index:" << index << std::endl;

    //        return nullptr;

    //        // Lösung 1:
    //        // return empty;  // Unschön, weil der Aufrufer nicht so wirklich
    //        //                // mitbekommt, dass der Index falsch ist.

    //        // Lösung 2:
    //        //                    "..."  const char*
    //        // std::string message = "Falscher Index an Stelle" + index;

    //        //std::string message1 = "Falscher Index an Stelle " + std::to_string(index);

    //        //std::string message2
    //        //    = std::string("Falscher Index an Stelle ") + std::to_string(index);

    //        ////std::string message3
    //        ////    = std::string("Falscher Index an Stelle ").append(std::to_string(index));

    //        //throw std::out_of_range(message1);
    //    }
    //}

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

    void resize(int newLength) {

        // allocate new buffer
        int* newBuffer = new int[newLength];

        // Stillschweigend: Nehme an, dass neue Länge größer ist als alte Länge
        
        // umkopieren
        for (int i = 0; i < m_length; ++i) {
            newBuffer[i] = m_data[i];
        }

        // Rest des neuen Puffers auf 0 vorbelegen
        for (int i = m_length; i < newLength; ++i) {
            newBuffer[i] = 0;
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

void test_dynamic_array_04()
{
    DynamicArray da(5);
    da.initialize(123);
    da.print();

    da.resize(8);
    da.print();
}

void test_dynamic_array_05()
{
    DynamicArray da(5);
    da.initialize(123);
    da.print();

    da.setAt(1, 100);
    da.print();

    // Lesen
    int value = da.getAt(2);

    // Attraktiver ... Yes !!!
    // Spielerei .. aber, aber
    value = da.operator[](2);

    // Ohne Spielerei:
    value = da[2];

    da.print();

    // Es gibt KEINE Null-Referenz
    // int& rvalue; //  = da[1];
    int& rvalue = da[1];

    rvalue = 999;

    da.print();

    // Jetzt wird es interessant:
    da[0] = 456;

    // Referenzen 
}

void test_dynamic_array_06()
{
    // Ausnahmebehandlung

    DynamicArray da(5);
    da.initialize(123);
    da.print();

    da[12] = 999;   // FALSCHER INDX

    try
    {
        int value = da[10];
        // oder
        da[12] = 999;
    }

    catch (std::overflow_error ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::out_of_range ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }


    da.print();
}

//void test_dynamic_array_07()
//{
//    DynamicArray da(5);
//    da.initialize(123);
//    da.print();
//
//    da.setAt(1, 100);
//    da.print();
//
//    // Lesen
//    int value = da.getAt(2);
//
//    // Ohne Spielerei - LESEND
//    int* pvalue = da[2];
//    std::cout << *pvalue << std::endl;
//
//    // SCHREIBEND - Jetzt wird es interessant:
//    *(da[0]) = 456;
//    da.print();
//
//    // ABER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//    // LESEND
//    pvalue = da[20];
//    if (pvalue != nullptr) {
//        std::cout << *pvalue << std::endl;
//    }
//
//    // SCHREIBEND - Jetzt wird es interessant:
//    //*(da[20]) = 456;
//    //da.print();
//
//    pvalue = da[20];
//    if (pvalue != nullptr) {
//        *pvalue = 456;
//    }
//}

void test_dynamic_array()
{
    test_dynamic_array_06();
    std::cout << "Done." << std::endl;
}