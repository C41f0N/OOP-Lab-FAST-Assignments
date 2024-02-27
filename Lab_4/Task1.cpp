#include <iostream>

using namespace std;

class ElectricityBill
{
    int consumerNumber;
    string consumerName, typeOfConnection;
    float previousMonthReading, currentMonthReading;
    float costCommercial[4] = {2, 4.5, 6, 7};
    float costDomestic[4] = {1, 2.5, 4, 6};

public:
    float calculate()
    {
        float totalBill = 0;

        float totalUnits = (float)currentMonthReading - previousMonthReading;
        float unitsToCalc = totalUnits;
        if (typeOfConnection == "D")
        {
            // if > 500
            if (unitsToCalc > 500)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc - 500) * costDomestic[3]);
                unitsToCalc = 500;
            }

            // if > 200
            if (unitsToCalc > 200)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc - 200) * costDomestic[2]);
                unitsToCalc = 200;
            }

            // if > 100
            if (unitsToCalc > 100)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc - 100) * costDomestic[1]);
                unitsToCalc = 100;
            }

            if (unitsToCalc > 0)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc)*costDomestic[0]);
                unitsToCalc = 0;
            }
        }

        else if (typeOfConnection == "C")
        {
            totalBill = 0;
            float unitsToCalc = totalUnits;
            // if > 500
            if (unitsToCalc > 500)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc - 500) * costCommercial[3]);
                unitsToCalc = 500;
            }

            // if > 200
            if (unitsToCalc > 200)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc - 200) * costCommercial[2]);
                unitsToCalc = 200;
            }

            // if > 100
            if (unitsToCalc > 100)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc - 100) * costCommercial[1]);
                unitsToCalc = 100;
            }

            if (unitsToCalc > 0)
            {
                // chop off the > 500 part and add that cost
                totalBill += (float)((unitsToCalc)*costCommercial[0]);
                unitsToCalc = 0;
            }
        }
        return totalBill;
    }

    ElectricityBill()
    {
        cout << "Welcome to Electricity Bill Generator." << endl;
    }

    void getInput()
    {
        cout << "Enter Consumer Number: ";
        cin >> consumerNumber;

        cout << "Enter type of connection (D for domestic & C for Commercial): ";
        cin >> typeOfConnection;

        cout << "Enter Consumer Name: ";
        cin >> consumerName;

        cout << "Enter previous month reading: ";
        cin >> previousMonthReading;

        cout << "Enter current month reading: ";
        cin >> currentMonthReading;
    }

    void display()
    {
        cout << endl
             << "BILL DISPLAY:" << endl;

        cout << "Consumer Number: " << consumerNumber << endl;

        cout << "Type of connection: " << typeOfConnection << endl;

        cout << "Consumer Name: " << consumerName << endl;

        cout << "Previous month reading: " << previousMonthReading << endl;

        cout << "Current month reading: " << currentMonthReading << endl;

        cout << "Current month reading: " << currentMonthReading << endl;

        cout << "Total Units: " << (float)currentMonthReading - previousMonthReading << endl;

        cout << "Total Bill: " << calculate() << endl;
    }
};

int main()
{
    ElectricityBill myBill;

    bool running = true;

    while (running)
    {
        myBill.getInput();
        myBill.display();

        cout
            << "Enter 0 if you want to exit: ";
        cin >> running;
    }

    return 0;
}
