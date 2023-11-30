#include <iostream>

using namespace std;

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

//int main_hello_world()
//{
//    std::cout << "Hello World" << std::endl;
//
//    double ergebnis = tueWas();
//
//    std::cout << "tueWas: " << ergebnis << std::endl;
//
//    return 0; 
//}

int main_hello_world()
{
    using namespace std;  // Vorsicht: 
    
    cout << "Hello World" << endl;

    double ergebnis = tueWas();

    cout << "tueWas: " << ergebnis << endl;

    return 0;
}

int main()
{
    try
    {
        exerciseMoreBankAccounts();
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

    return 1;
}
