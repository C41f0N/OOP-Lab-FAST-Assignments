#include <iostream>

using namespace std;

float fuelMilage = 2;

class Passenger
{

    string id, phoneNumber, pickup, dropoff, type;
    float distanceToTravel;

public:
    Passenger(
        string phoneNumber,
        string pickup,
        string dropoff,
        string type,
        float distanceToTravel)
        : phoneNumber(phoneNumber),
          pickup(pickup),
          dropoff(dropoff),
          type(type),
          distanceToTravel(distanceToTravel) {}

    float getDistanceToTravel()
    {
        return distanceToTravel;
    }

    string getType()
    {
        return this->type;
    }
};

class Driver
{
    string name, id;
    float fuelQuota, totalEarnings;
    int alphaCount, betaCount, gammaCount;

public:
    Driver(
        string name,
        string id)
        : name(name),
          id(id),
          fuelQuota(0.0),
          alphaCount(0),
          betaCount(0),
          gammaCount(0),
          totalEarnings(0){};

    void assignQuota(float quota)
    {
        this->fuelQuota = quota;
    }

    void assignPassenger(Passenger &passenger)
    {
        float fuelConsumption, cost, fuel;
        fuel = (float)(passenger.getDistanceToTravel() * fuelMilage);
        if (passenger.getType() == "alpha" && fuel <= this->fuelQuota)
        {
            fuelConsumption = 150;

            this->alphaCount++;
            cost = (float)fuel * fuelConsumption;
            this->totalEarnings += (float)cost;
            this->fuelQuota -= (passenger.getDistanceToTravel() * fuelMilage);
        }
        else if (passenger.getType() == "beta" && fuel <= this->fuelQuota)
        {
            fuelConsumption = 100;

            this->betaCount++;
            cost = (float)fuel * fuelConsumption;
            this->totalEarnings += (float)cost;
            this->fuelQuota -= (passenger.getDistanceToTravel() * fuelMilage);
        }
        else if (passenger.getType() == "gamma" && fuel <= this->fuelQuota)
        {
            fuelConsumption = 70;

            this->gammaCount++;
            cost = (float)fuel * fuelConsumption;
            this->totalEarnings += (float)cost;
            this->fuelQuota -= (passenger.getDistanceToTravel() * fuelMilage);
        }
        else
        {
            cout << "[-] Passenger not assigned." << endl;
        }
    }

    void printStats()
    {
        cout << endl
             << "===============================" << endl;
        cout << "  DRIVER STATS" << endl;
        cout << "===============================" << endl
             << endl;

        cout << "ID: " << this->id << endl;
        cout << "Fuel Left: " << this->fuelQuota << endl;

        if (this->alphaCount > this->betaCount && this->alphaCount > this->gammaCount)
        {
            cout << "Total Earnings: " << this->totalEarnings + 500 << endl;
        }
        else
        {
            cout << "Total Earnings: " << this->totalEarnings << endl;
        }
    }
};

int main()
{
    // Initializing Driver
    Driver driver("Sarim", "0703");

    // Initializing Passengers
    Passenger passengers[5] = {
        Passenger("1234567890", "Munawar Chorangi", "Sadar", "alpha", 1),
        Passenger("1823459670", "Johar Chorangi", "Sadar", "beta", 3),
        Passenger("1267893450", "NIPA", "Sadar", "alpha", 2),
        Passenger("1456782390", "Continental", "Sadar", "gamma", 5),
        Passenger("1239045678", "Kamran Chorangi", "Sadar", "alpha", 9),
    };

    // Assinging quota
    driver.assignQuota(100);

    for (int i = 0; i < 5; i++)
    {
        driver.assignPassenger(passengers[i]);
        driver.printStats();
    }
}