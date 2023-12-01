#include <iostream>
#include <vector>
#include <algorithm>

void test_stl_01()
{
    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    for (int i = 0; i < numbers.size(); ++i) {

        std::cout << i << ": " << numbers[i] << std::endl;
    }
}

void test_stl_02()
{
    // Besser - weil STL konformer 

    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    std::vector<int>::iterator pos = numbers.begin();

    // Element an der ersten Stelle
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers erreicht !" << std::endl;
        return;
    }
    int value = *pos;
    std::cout << value << std::endl;

    // Element an der zweiten Stelle
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers erreicht !" << std::endl;
        return;
    }

    value = *pos;
    std::cout << value << std::endl;

    // Element an der dritten Stelle
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers erreicht !" << std::endl;
        return;
    }

    value = *pos;
    std::cout << value << std::endl;

    // Element an der vierten Stelle
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Ende des Containers erreicht !" << std::endl;
        return;
    }

    value = *pos;
    std::cout << value << std::endl;
}


void test_stl_03()
{
    // Besser - weil STL konformer 

    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    std::vector<int>::iterator pos = numbers.begin();
    std::vector<int>::iterator end = numbers.end();

    while (pos != end) {

        int value = *pos;
        std::cout << value << std::endl;

        ++pos;
    }

    std::cout << "Ende des Containers erreicht !" << std::endl;
}

void test_stl_04()
{
    // Besser - weil STL konformer 

    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    std::vector<int>::iterator pos = numbers.begin();
    std::vector<int>::iterator end = numbers.end();

    for ( ; pos != end; ++pos) {

        int value = *pos;
        std::cout << value << std::endl;   // gebeAus

    }

    std::cout << "Ende des Containers erreicht !" << std::endl;
}


class Output
{
private:
    int m_number;

public:
    Output(int number) { m_number = number; }
    Output() : Output (0) {}

    // operators
    void operator() () {
        
        std::cout << "Wert: " << m_number << std::endl;
    }

    // Überladen 
    void operator() (int newNumber) {

        m_number = newNumber;

        std::cout << "Wert: " << m_number << std::endl;
    }
};



void test_stl_05()
{
    Output o;
    Output o1(123);

    o();
    o1();

    o(456);
    o1(123);
}

// ====================================================

int g_sum = 0;

void gebeAusUndBerechneSumme(int value)
{
    g_sum += value;
    std::cout << value << std::endl;
}

void test_stl_06()
{
    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    std::for_each(               // type deduction // Typ Ableitung
        numbers.begin(),
        numbers.end(),
        gebeAusUndBerechneSumme
    );

    std::cout << "Summe: " << g_sum << std::endl;
}

// ====================================================

class VectorInformation
{
private:
    int m_sum;

public:
    VectorInformation() { m_sum = 0; }

    int getSum() { return m_sum; }

    // operators
    void operator() (int nextNumber) {

        m_sum += nextNumber;

        std::cout << "Wert: " << nextNumber << std::endl;
    }
};

void test_stl_07()
{
    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    VectorInformation info;

    std::for_each(
        numbers.begin(),
        numbers.end(),
        info  // Dieses Objekt über einen ALIAS (referenz) an std::for_each zu übergeben
              // Nope: Never 
    );

    std::for_each(               
        numbers.begin(),
        numbers.end(),
        std::ref(info)  // Übergebe einen ALIAS auf das info Objekt
    );

    std::cout << "Summe: " << info.getSum() << std::endl;
}

void test_stl_08()
{
    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.push_back(11);       // Feld der Länge 1
    numbers.push_back(12);       // Feld der Länge 2
    numbers.push_back(13);       // Feld der Länge 3

    VectorInformation info;

    VectorInformation result = std::for_each(
        numbers.begin(),
        numbers.end(),
        info
    );

    std::cout << "Summe: " << result.getSum() << std::endl;
}

void test_stl_09()
{
    std::vector<int> numbers(20);  // leer // Feld der Länge 0

    // 1. Variante:
    for (int i = 0; i < numbers.size(); ++i) {

        numbers[i] = 1;
    }

    Output out;

    std::for_each(
        numbers.begin(),
        numbers.end(),
        out
    );

    // VERSUS ........................

    // 2. Variante:

    std::fill(
        numbers.begin(),
        numbers.end(),
        2
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        out
    );
}

class Vorbeleger
{
private:
    int m_start;

public:
    // Ret func();

    Vorbeleger() : m_start () {}

    int operator() () {

        m_start++;

        std::cout << " ... bin hier: " << m_start << std::endl;

        return m_start;
    }
};

void test_stl_10()
{
    std::vector<int> numbers(20);  // leer // Feld der Länge 0

    Vorbeleger vb;

    std::generate(
        numbers.begin(),
        numbers.end(),
        vb
    );

    Output out;

    std::for_each(
        numbers.begin(),
        numbers.end(),
        out
    );
}

void test_stl_10_advanced()
{
    std::vector<int> numbers;  // leer // Feld der Länge 0

    numbers.resize(20);

    // über den Tellerrand: C# (delegates, lambda) // Java // JavaScript
    // Funktionen - ohne Namen // anonyme Funktion
    // Diese Funktion gehört zu einer Klasse // anonyme Methode
    // Design-Entscheidung: anonyme Methode ist mit 'const' markiert
    // "const-Entferner": mutable
    // m_start ist vom Typ int, weil 10 eine int-Konstante ist
    // Type Deduction

    std::generate(
        numbers.begin(),
        numbers.end(),
        [m_start = 10] ( ) mutable -> int {

            m_start++;
            std::cout << " ... bin hier: " << m_start << std::endl;
            return m_start;
        }
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [] (int value ) {
            std::cout << "Wert: " << value << std::endl;
        }
    );
}


// ===================================================

void test_stl_11()
{
    std::vector<int> numbers;

    numbers.reserve(90);

    for (int i = 0; i < 100; ++i) {

        numbers.push_back(i);

        std::cout 
            << "i: " << i << " - size: " << numbers.size() 
            << " - capacity: " << numbers.capacity() << std::endl;
    }

    // am Ende

    numbers.shrink_to_fit();

    std::cout
        << "size: " << numbers.size()
        << " - capacity: " << numbers.capacity() << std::endl;
}

void test_stl_12()
{
    std::vector<int> numbers;

    numbers.reserve(90);

    for (int i = 0; i < 100; ++i) {

        numbers.push_back(i);

        std::cout
            << "i: " << i << " - size: " << numbers.size()
            << " - capacity: " << numbers.capacity() << std::endl;
    }

    // =======================================
    // Suchen

    std::vector<int>::iterator pos = std::find(
        numbers.begin(),
        numbers.end(),
        555
    );

    if (pos == numbers.end()) {

        std::cout << "Element nicht gefunden !!!" << std::endl;
    }
    else {

        std::cout << "Element gefunden: " << *pos <<  std::endl;
    }
}


void test_stl()
{
    test_stl_10_advanced();
}