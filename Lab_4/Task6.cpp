#include <iostream>

using namespace std;

class Office
{

    string location;
    int seatingCapacity;
    string *furniture;

public:
    Office(string location = "Karachi", int seatingCapacity = 0, int furnitureQuantity = 3) : location(location), seatingCapacity(seatingCapacity)
    {
        furniture = new string[furnitureQuantity];
    }

    ~Office()
    {
        delete[] furniture;
    }
};

int main()
{

    Office *office = new Office("Lahore", 12, 10);
    delete office;
}