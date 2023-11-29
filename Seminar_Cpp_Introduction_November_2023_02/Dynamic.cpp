#include <iostream>
#include <string>


int g_counter = 0;

void tueWas(int* ptr)
{
   // arbeitet mit den Daten
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
}

void tueWasEx(int* ptr, int count)
{
    // Hard-Core
    for (int i = 0; i < count; ++count) {

        // vorbelegen mit 1
        * (ptr + i)  = 1;         // identisch mit ptr[i]
                                  // *(ptr + i)
    }

    // Easy-Going
    for (int i = 0; i < count; ++count) {

        // vorbelegen mit 1
        ptr[i] = 1;
    }

    // arbeitet mit den Daten
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;
}

void test_dynamic_01()
{
    int tmp = 123;

    int* ip = new int(456);

    tueWas(ip); 

    delete ip;
}

void test_dynamic_02()
{
    int wieviele = 10;

    // int zahlen[wieviele];  // Array

    int* ip = new int [wieviele];

    tueWasEx(ip, wieviele);

    delete[] ip;
}

int getWert() { return 123; }


struct EinWert
{
    int             m_wert;
    struct EinWert* m_next;
};

void test_frage()
{
    while (true)
    {
        int nextWertVonSensor = getWert();

        // hier sind wir
        struct EinWert* aktuell = new struct EinWert;
        aktuell->m_wert = 99;
        aktuell->m_next = nullptr;

    }



}



void test_dynamic()
{
    test_dynamic_02();
}
