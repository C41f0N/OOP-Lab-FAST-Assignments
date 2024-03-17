#include <iostream>

using namespace std;

class Package
{
    string name, address, city, state, zipCodeReciever, zipCodeSender;
    float weight, costPerOunce;

public:
    Package(
        string name,
        string address,
        string city,
        string state,
        string zipCodeReciever,
        string zipCodeSender,
        float weight,
        float costPerOunce)
        : name(name),
          address(address),
          city(city),
          state(state),
          zipCodeReciever(zipCodeReciever),
          zipCodeSender(zipCodeSender),
          weight(weight),
          costPerOunce(costPerOunce)
    {
    }

    void authentication()
    {
        if (this->weight < 0 || this->costPerOunce < 0)
        {
            cout << "Incorrect Input" << endl;
        }
    }

    float calculateCost()
    {
        return this->weight * this->costPerOunce;
    }

    float getCostPerOunce()
    {
        return costPerOunce;
    }

    float getWeight()
    {
        return weight;
    }
};

class TwoDayPackage : protected Package
{
    float flatCost;

public:
    TwoDayPackage(
        string name,
        string address,
        string city,
        string state,
        string zipCodeReciever,
        string zipCodeSender,
        float weight,
        float costPerOunce,
        float flatCost)
        : flatCost(flatCost),
          Package(
              name,
              address,
              city,
              state,
              zipCodeReciever,
              zipCodeSender,
              weight,
              costPerOunce)
    {
    }

    float flatfee()
    {
        return this->flatCost + (getWeight() * getCostPerOunce());
    }
};

class OvernightPackage : protected Package
{
    float additionalCost;

public:
    OvernightPackage(
        string name,
        string address,
        string city,
        string state,
        string zipCodeReciever,
        string zipCodeSender,
        float weight,
        float costPerOunce,
        float additionalCost)
        : additionalCost(additionalCost),
          Package(
              name,
              address,
              city,
              state,
              zipCodeReciever,
              zipCodeSender,
              weight,
              costPerOunce)
    {
    }

    float calculateAdditional()
    {
        return this->additionalCost + (getWeight() * getCostPerOunce());
    }
};

int main()
{
    // Testing two day packages
    TwoDayPackage twoDayPackages[2] = {
        TwoDayPackage("PS3", "A-213", "Karachi", "Sindh", "1234", "4321", 20.0, 1.2, 500),
        TwoDayPackage("PS$", "A-213", "Lahore", "Punjab", "1234", "4321", 10.0, 1.2, 500),
    };

    cout << "Two Day Packages:" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << i << ": " << twoDayPackages[i].flatfee() << endl;
    }

    // Testing overnight packages
    OvernightPackage overnightPackages[2] = {
        OvernightPackage("PS3", "A-213", "Karachi", "Sindh", "1234", "4321", 20.0, 1.2, 700),
        OvernightPackage("PS$", "A-213", "Lahore", "Punjab", "1234", "4321", 10.0, 1.2, 700),
    };

    cout << endl
         << "Overnight Packages:" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << i << ": " << overnightPackages[i].calculateAdditional() << endl;
    }
}