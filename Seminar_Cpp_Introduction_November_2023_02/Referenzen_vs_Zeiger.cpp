#include <iostream>


void test_pointer()
{
    int wieGross = sizeof(int);  // in Bytes

    int n = 123;

    // Adresse von n

    int* ip2 = nullptr;

    // int value = *ip2;   // Absturz

    if (ip2 == nullptr) {
        // habe hier keine gültige Adresse ... reagieren
    }

                    // Variablendeklaration: ip // Declaration
    int* ip = &n;   // Links: Datentyp int*: "Adresse einer int-Variablen"
                    // Rechts: Operator &:   "Adresse-von-einer-Variablen" 

    // Wertzuweisung von 456 an n - ohne den Bezeichner 'n' dabei zu verwenden
    // Anweisung // Statement
    // Links: Operator* : Indirekter Zugriff auf eine Speicherzelle mit Hilfe einer Adresse
    *ip = 456;

    n = 789;            // Direkter Zugriff   

    // Zeiger - Arithmetik

    ip++;       // vorher: ip:  1024 // Danach: 1028: Warum: Alte Adresse + sizeof (int)
    // oder
    // ip = ip + 1;

    int m = *ip;

    ip--;
    m = *ip;
}


void test_reference()
{
    int m = 123;

    int& ri = m;           // int&: Deklariert / Vereinbart eine Referenz einer Variablen des Typs 'int'

    ++m;

    int value = m;

    value = ri;

    ++ri;      // Erwartung: m wird um den Wert 1 inkrementiert (NICHT die Adresse)

    ++m;

    value = m;
}

void test_pointer_02()
{
    int n = 123;

    int* ip = &n;

    int** ipp = &ip;    // hierfür gibt es Anwendungen

    int*** ippp = &ipp;   // hierfür eher weniger Anwendungsfälle
}


void malDrei(int value)
{
    int tmp = value;

    tmp = tmp * 3;

    value = tmp;
}

// Lösung mit Pointer / Adresse  (C/C++)
void malDreiEx(int* pvalue)
{
    int tmp = *pvalue;   // Wert-von // Value-of // Indirekter lesender Zugriff
                         // dereferenzieren
    tmp = tmp * 3;

    *pvalue = tmp;        // Indirekter schreibener Zugriff
}

// Lösung mit Referenz (C++)
void malDreiExEx(int& rvalue)
{
    int tmp = rvalue;

    tmp = tmp * 3;

    rvalue = tmp;
}



void test_references()
{
    int x = 123;
    std::cout << "Vorher:  " << x << std::endl;

    malDrei(x);
    std::cout << "Nachher: " << x << std::endl;

    malDreiEx(&x);
    std::cout << "Nachher: " << x << std::endl;

    malDreiExEx(x);
    std::cout << "Nachher: " << x << std::endl;
}