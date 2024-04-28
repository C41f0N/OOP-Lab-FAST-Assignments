#include <iostream>

using namespace std;

class Vehicle
{
    string id;
    int producedYear;
    float odometerReading;

public:
    Vehicle(
        string id,
        int producedYear,
        float odometerReading)
        : id(id),
          producedYear(producedYear),
          odometerReading(odometerReading) {}

    virtual string getType() = 0;
    virtual float getCost() = 0;
};

class CompactCar : public Vehicle
{

public:
    CompactCar(
        string id,
        int producedYear,
        float odometerReading)
        : Vehicle(
              id,
              producedYear,
              odometerReading) {}

    string getType()
    {
        return "compact";
    }

    float getCost()
    {
        return 10;
    }
};

class StandardCar : public Vehicle
{
public:
    StandardCar(
        string id,
        int producedYear,
        float odometerReading)
        : Vehicle(
              id,
              producedYear,
              odometerReading) {}

    string getType()
    {
        return "standard";
    }

    float getCost()
    {
        return 20;
    }
};

class LuxuryCar : public Vehicle
{
public:
    LuxuryCar(
        string id,
        int producedYear,
        float odometerReading)
        : Vehicle(
              id,
              producedYear,
              odometerReading) {}

    string getType()
    {
        return "luxury";
    }

    float getCost()
    {
        return 30;
    }
};

class Customer
{
    string name;
    string address;
    string liscense;
    int age;
    string creditCard;

public:
    Customer(string name, string address, string liscense, int age, string creditCard)
    {
        if (age >= 18)
        {
            this->name = name;
            this->address = address;
            this->liscense = liscense;
            this->age = age;
            this->creditCard = creditCard;
        }
    }

    bool isYoung()
    {
        return age <= 25;
    }
};

class Contract
{
    Customer *customer;
    Vehicle *vehicle;
    int startDate, endDate;
    float youngAgeFee, weeklyRate, monthlyRate;

public:
    Contract(
        Customer *customer,
        Vehicle *vehicle,
        int startDate,
        int endDate,
        float youngAgeFee)
        : customer(customer),
          vehicle(vehicle),
          startDate(startDate),
          endDate(endDate),
          youngAgeFee(youngAgeFee) {}

    float getFee()
    {
        float rate;
        if (endDate - startDate <= 7)
        {
            rate = 50;
        }
        else
        {
            rate = 100;
        }

        if (customer->isYoung())
        {
            return vehicle->getCost() * (rate)-youngAgeFee;
        }
        else
        {
            return vehicle->getCost() * (endDate - startDate);
        }
    }
};

int main() {}