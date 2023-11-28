
class Calculator
{
public:
    static const double Pi;

public:
    static int add(int x, int y) {
        return x + y;
    }

    static int sub(int x, int y) {
        return x - y;
    }
};

// Speicher f�r Pi explizit anlegen:
const double Calculator::Pi = 3.14;   // Vorbelegung ist eine Ausnahme f�r 'const'

// besser strukturieren in einer Klasse // verstecken // einen Namen zuordnen 
//int add(int x, int y) { return x + y; }
//int sub(int x, int y) { return x + y; }
//int mul(int x, int y) { return x + y; }
//int div(int x, int y) { return x + y; }


void test_statisches()
{
    // Calculator myCalc;

    int result = Calculator::add(3, 4);    // "globale Funktion" // geh�rt zu einer Klasse

                                           // Calculator::add

    double radius = 2.0;

    double fl�che = radius * radius * Calculator::Pi;

    // Calculator::Pi = 999.99;
}
