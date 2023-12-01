#include <iostream>

#include "DynamicArrayTemplate.h"

#include "Time.h"

//class Calculator
//{
//public:
//    static int add(int x, int y) { return x + y; }
//    static int sub(int x, int y) { return x - y; }
//    static int mul(int x, int y) { return x * y; }
//    static int div(int x, int y) { return x / y; }
//};
//
//
//class DoubleCalculator
//{
//public:
//    static double add(double x, double y) { return x + y; }
//    static double sub(double x, double y) { return x - y; }
//    static double mul(double x, double y) { return x * y; }
//    static double div(double x, double y) { return x / y; }
//};

// Generic Programming:  Schablone für Klassen => Konkrete Klasse => Objekt

// Instanziierung: Von der Klasse zum Objekt
// Instanziierung: Von der Schablone zur Klasse


template <typename T>
class Calculator
{
private:
    T lastResult;

public:
    static T add(T x, T y) { return x + y; }
    static T sub(T x, T y) { return x - y; }
    static T mul(T x, T y) { return x * y; }
    static T div(T x, T y) { return x / y; }

    T addNS(const T x, const T y) {

        T tmp = x + y;

        lastResult = tmp;

        return tmp;
    }


    T subNS(T x, T y) { return x - y; }
    T mulNS(T x, T y) { return x * y; }
    T divNS(T x, T y) { return x / y; }
};


void test_templates_allgemein ()
{
    // Kleine Ausnahme: Es gibt statische Methoden

    int result;

    result = Calculator<int>::add(3, 4);

    double x;

    x = Calculator<double>::add(3.9, 4.4);

    result = Calculator<int>::add(33, 44);

    // ==================================

    // Regelcall

    Calculator<int> myCalc;

    int n = myCalc.addNS(44, 55);
}


void test_templates_frage()
{
    std::string a("111");

    std::string b("222");

    std::string result = Calculator<std::string>::add(a, b);
}





void test_templates_dyn_array_int()
{
    using namespace DynamicArrayTemplate;

    DynamicArray<int, 3> da;
    da.print();

    da.initialize(123);
    da.print();

    da.resize(8);
    da.print();
}


void test_templates_dyn_array_double()
{
    using namespace DynamicArrayTemplate;

    DynamicArray<double> da(7);

    da.initialize(5.55);
    da.print();

    da.resize(12);
    da.print();
}



void test_templates_dyn_array_string()
{
    using namespace DynamicArrayTemplate;

    DynamicArray<std::string> da(5);

    da.initialize(std::string("leer"));
    da.print();

    da.resize(8);
    da.print();
}


void test_templates_dyn_array_time()
{
    using namespace DynamicArrayTemplate;

    DynamicArray<Time> da(5);
    da.print();

    da.initialize(Time(10, 30, 0));
    da.print();

    da.resize(8);
    da.print();
}

void test_templates()
{
    test_templates_dyn_array_int();
}