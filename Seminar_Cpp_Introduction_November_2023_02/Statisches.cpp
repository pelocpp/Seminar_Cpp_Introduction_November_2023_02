
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

// Speicher für Pi explizit anlegen:
const double Calculator::Pi = 3.14;   // Vorbelegung ist eine Ausnahme für 'const'

// besser strukturieren in einer Klasse // verstecken // einen Namen zuordnen 
//int add(int x, int y) { return x + y; }
//int sub(int x, int y) { return x + y; }
//int mul(int x, int y) { return x + y; }
//int div(int x, int y) { return x + y; }


void test_statisches()
{
    // Calculator myCalc;

    int result = Calculator::add(3, 4);    // "globale Funktion" // gehört zu einer Klasse

                                           // Calculator::add

    double radius = 2.0;

    double fläche = radius * radius * Calculator::Pi;

    // Calculator::Pi = 999.99;
}
