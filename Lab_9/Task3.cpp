#include <iostream>

using namespace std;

class Car
{
    int modelNumber;
    int year;

public:
    Car(
        int modelNumber,
        int year)
        : modelNumber(modelNumber),
          year(year) {}

    virtual float calculateSalesPrice()
    {
        return 0.0;
    }

    virtual int getModelNumber()
    {
        return modelNumber;
    }

    virtual int getYear()
    {
        return year;
    }
};

class SportsCar : public Car
{
    float tax, salesPrice;

public:
    SportsCar(
        int modelNumber,
        int year,
        float tax,
        float salesPrice)
        : Car(
              modelNumber,
              year),
          tax(tax),
          salesPrice(salesPrice) {}

    float calculateSalesPrice()
    {
        return tax + salesPrice;
    }
};

class ClassicCar : public Car
{
    float salesPrice;

public:
    ClassicCar(
        int modelNumber,
        int year,
        float salesPrice)
        : Car(
              modelNumber,
              year),
          salesPrice(salesPrice) {}

    float calculateSalesPrice()
    {
        if (getYear() > 2000)
        {
            return salesPrice * 0.75;
        }
        else if (getYear() > 1995)
        {
            return salesPrice * 0.5;
        }
        else
        {
            return salesPrice * 0.25;
        }
    }
};

class SedanCar : public Car
{
    float discount, salesPrice;

public:
    SedanCar(
        int modelNumber,
        int year,
        float discount,
        float salesPrice)
        : Car(
              modelNumber,
              year),
          discount(discount),
          salesPrice(salesPrice) {}

    float calculateSalesPrice()
    {
        return salesPrice - discount;
    }
};

class Exhibition
{
    int year;
    int numCars;
    Car **cars;

public:
    Exhibition(int year) : year(year), numCars(0) {}

    void addCar(int modelNumber, int year)
    {
        Car **newCars = new Car *[numCars + 1];
        Car *car;

        // Copy old car data
        for (int i = 0; i < numCars; i++)
        {
            newCars[i] = cars[i];
        }

        // Get new car to add
        int option;

        cout << "Select the car you want to add:\n";
        cout << "[1] Sports Car\n";
        cout << "[2] Classic Car\n";
        cout << "[3] Sedan Car\n";
        cout << ": ";

        cin >> option;

        if (option == 1)
        {
            float tax, salesPrice;

            cout << "Enter car tax: ";
            cin >> tax;

            cout << "Enter car sales price: ";
            cin >> salesPrice;

            SportsCar sportsCar = SportsCar(modelNumber, year, tax, salesPrice);

            car = &sportsCar;
        }
        else if (option == 2)
        {
            float salesPrice;

            cout << "Enter car sales price: ";
            cin >> salesPrice;

            ClassicCar classicCar = ClassicCar(modelNumber, year, salesPrice);

            car = &classicCar;
        }
        else
        {
            float discount, salesPrice;

            cout << "Enter car sales price: ";
            cin >> salesPrice;

            cout << "Enter discount price: ";
            cin >> discount;

            SedanCar sedanCar = SedanCar(modelNumber, year, discount, salesPrice);
            car = &sedanCar;
        }

        // Add new car to list
        newCars[numCars] = car;

        // Dealloc old pointer
        if (numCars > 0)
        {
            delete[] cars;
        }

        cars = newCars;

        numCars++;
    }

    void displaySummary()
    {
        cout << "==========================================\n";
        cout << "               CARS SUMMARY\n";
        cout << "==========================================\n";

        for (int i = 0; i < numCars; i++)
        {
            cout << "Car #" << i + 1 << endl;
            cout << "Model Number: " << cars[i]->getModelNumber() << endl;
            cout << "Sales Price: " << cars[i]->calculateSalesPrice() << endl;

            cout << endl;
        }
    }
};

int main()
{
    Exhibition exhibition(2024);

    exhibition.addCar(1234, 2024);
    exhibition.addCar(1235, 1900);

    exhibition.displaySummary();
}