#include <iostream>

#include "MyFunctions.h"

// Funktion: a la C
double tueWas()
{
    std::cout << "Ich bin ein Unterprogramm" << std::endl;
    std::cout << "Ich bin ein Unterprogramm" << std::endl;
    std::cout << "Ich bin ein Unterprogramm" << std::endl;

    return 456.456456;
}

void ausgabe()
{
    std::cout << "Ich bin ein Unterprogramm" << std::endl;
    std::cout << "Ich bin ein Unterprogramm" << std::endl;
    std::cout << "Ich bin ein Unterprogramm" << std::endl;
}

int main_hello_world()
{
    std::cout << "Hello World" << std::endl;

    double ergebnis = tueWas();

    std::cout << "tueWas: " << ergebnis << std::endl;

    return 0; 
}

int main()
{
    exerciseBankAccount();

    return 1;
}
