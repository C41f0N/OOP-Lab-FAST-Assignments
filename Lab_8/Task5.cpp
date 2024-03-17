#include <iostream>
#include <cmath>

using namespace std;

class Box
{
public:
    int capacity;
    float cost;

    Box(int capacity, float cost) : capacity(capacity), cost(cost) {}
};

class LargeBox : public Box
{
public:
    LargeBox() : Box(20, 1.8) {}
};

class MediumBox : public Box
{
public:
    MediumBox() : Box(10, 1.0) {}
};

class SmallBox : public Box
{
public:
    SmallBox() : Box(5, 0.5) {}
};

class Coffee
{
    SmallBox smallBoxSample;
    MediumBox mediumBoxSample;
    LargeBox largeBoxSample;
    float cost;
    int numLargeBoxes, numMediumBoxes, numSmallBoxes, orderCapacity;

public:
    Coffee(int orderCapacity) : orderCapacity(orderCapacity) {}

    void calculateOrder()
    {
        int capacityToSort = orderCapacity;

        // Put in large boxes
        numLargeBoxes = (int)(capacityToSort / largeBoxSample.capacity);
        capacityToSort -= (numLargeBoxes * largeBoxSample.capacity);

        // Put in medium boxes
        numMediumBoxes = (int)(capacityToSort / mediumBoxSample.capacity);
        capacityToSort -= (numMediumBoxes * mediumBoxSample.capacity);

        // Put in small boxes
        numSmallBoxes = ceil((capacityToSort / smallBoxSample.capacity));
        capacityToSort = 0;

        // Calculate cost
        cost = (numLargeBoxes * largeBoxSample.cost) + (numMediumBoxes * mediumBoxSample.cost) + (numSmallBoxes * smallBoxSample.cost);
    }

    void display()
    {

        cout << "Number of Bags Ordered: " << orderCapacity << endl;
        cout << "The Cost of Order: $" << cost << endl;
        cout << "Boxes Used:" << numLargeBoxes + numMediumBoxes + numSmallBoxes << endl;
        cout << numLargeBoxes << " Large - $" << largeBoxSample.cost * numLargeBoxes << endl;
        cout << numMediumBoxes << " Medium - $" << mediumBoxSample.cost * numMediumBoxes << endl;
        cout << numSmallBoxes << " Small - $" << smallBoxSample.cost * numSmallBoxes << endl;
        cout << "Your total cost is: $" << cost << endl;
    }
};

int main()
{
    int capacity;

    cout << "Enter order capacity: ";
    cin >> capacity;

    Coffee coffeeOutlet(capacity);

    coffeeOutlet.calculateOrder();
    coffeeOutlet.display();
}