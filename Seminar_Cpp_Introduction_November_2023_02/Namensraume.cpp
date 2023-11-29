#include <iostream>

// using namespace Project_Data_Management;   // Geht !!! , bin da aber kein Freund davon ;)


using namespace std;


// List:  Container Daten // UI Element  ListBox

namespace Project_UI {

    class Circle
    {
    public:
        double area() { return 0.0; }
    };
}

namespace Project_Data_Management {

    namespace Circle_Data
    {
        class Circle
        {
        public:
            double area() { return 0.0; }
        };
    }
}

namespace Project_UI
{
    
    void test_namespaces_01()
    {

       //  using namespace Project_UI;

        Circle circle;
    }
}



void test_namespaces_02()
{
    Project_UI::Circle circle;    // safe
}

void test_namespaces_03()
{
    using namespace Project_Data_Management;

    Project_UI::Circle circle1;

    // Circle circle2;   // stammt aus Project_Data_Management
}

void test_namespaces_04()
{
    int tmp = 123;

    // Project_Data_Management::Circle_Data::Circle circle;

    // oder

    //using namespace Project_Data_Management::Circle_Data;
    //Circle circle;

    // oder

   // Circle_Data::Circle circle;

}


void test_namespaces_05()
{
    using Project_UI::Circle;

    using std::cout;

   // using Project_Data_Management::Circle_Data::Circle;

    Circle circle;


    Project_Data_Management::Circle_Data::Circle circle2;

    cout << "Ahaaa";
}
