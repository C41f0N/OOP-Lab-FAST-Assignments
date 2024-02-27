#include <iostream>

using namespace std;

class Office
{

    string location;
    int seatingCapacity;
    string furniture[3] = {"", "", ""};

public:
    Office(string location = "Karachi", int seatingCapacity = 0, string furniture1 = "", string furniture2 = "", string furniture3 = "") : location(location), seatingCapacity(seatingCapacity), furniture{furniture1, furniture2, furniture3} {}

    void displayData()
    {
        cout << "Location: " << location << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Furniture 1: " << furniture[0] << endl;
        cout << "Furniture 2: " << furniture[1] << endl;
        cout << "Furniture 3: " << furniture[2] << endl
             << endl;
    }
};

int main()
{
    Office office1;
    Office office2("Lahore");
    Office office3("Lahore", 2);
    Office office4("Lahore", 2, "Cupboard");
    Office office5("Lahore", 2, "Cupboard", "Desk");
    Office office6("Lahore", 2, "Cupboard", "Desk", "Chair");

    office1.displayData();
    office2.displayData();
    office3.displayData();
    office4.displayData();
    office5.displayData();
    office6.displayData();
}