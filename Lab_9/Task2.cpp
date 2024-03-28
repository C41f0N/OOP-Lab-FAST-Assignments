#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Base Desert Item Class
class DessertItem
{
    string name;
    float calories;

public:
    DessertItem(string name) : name(name) {}

    void setCalories(float calories)
    {
        this->calories = calories;
    }

    string getName()
    {
        return name;
    }

    float getCalories()
    {
        return calories;
    }

    virtual int getCost()
    {
        return 0;
    }
};

// Candy Class
class Candy : public DessertItem
{
    float weight, pricePerPound;

public:
    Candy(string name,
          float weight,
          float pricePerPound)
        : DessertItem(name),
          weight(weight),
          pricePerPound(pricePerPound) {}

    int getCost()
    {
        return round(weight * pricePerPound);
    }
};

// Cookie Class
class Cookie : public DessertItem
{
    int number;
    float pricePerDozen;

public:
    Cookie(string name,
           float number,
           float pricePerDozen)
        : DessertItem(name),
          number(number),
          pricePerDozen(pricePerDozen) {}

    int getCost()
    {
        return round(number * (pricePerDozen / 12));
    }
};

// IceCream Class
class IceCream : public DessertItem
{
    float cost;

public:
    IceCream(string name,
             float cost)
        : DessertItem(name),
          cost(cost) {}

    virtual int getCost()
    {
        return cost;
    }
};

// Sundae Class
class Sundae : public IceCream
{
    float cost, toppingCost;

public:
    Sundae(string name,
           float toppingCost,
           float iceCreamCost)
        : IceCream(
              name,
              iceCreamCost),
          toppingCost(toppingCost)
    {
        cost = iceCreamCost + toppingCost;
    }

    int getCost()
    {
        return (int)cost;
    }
};

// Checkout Class
class Checkout
{
    int totalTax, numDessertItems;
    float taxRate;
    DessertItem **dessertItems;

public:
    Checkout()
    {
        // Setting tax rate to 3%
        taxRate = 0.03;

        numDessertItems = 0;
    }

    void addDessertItemToRegister(DessertItem *dessertItem)
    {
        // Create new dessert item list with 1 more length
        DessertItem **newDessertItems = new DessertItem *[numDessertItems + 1];

        // Copy data from old list to new list
        for (int i = 0; i < numDessertItems; i++)
        {
            newDessertItems[i] = dessertItems[i];
        }

        // Add new item to list end
        newDessertItems[numDessertItems] = dessertItem;

        // Delete the old list
        if (numDessertItems > 0)
        {
            delete[] dessertItems;
        }

        // Replace old list pointer with new list pointer
        dessertItems = newDessertItems;

        numDessertItems++;
    }

    int getTotal()
    {
        int total = 0;

        for (int i = 0; i < numDessertItems; i++)
        {
            total += dessertItems[i]->getCost();
        }

        return total;
    }

    void clearRegister()
    {
        if (numDessertItems > 0)
        {
            delete[] dessertItems;
        }

        numDessertItems = 0;
    }

    int getNumberOfItems()
    {
        return numDessertItems;
    }

    int getTotalTax()
    {
        return round(taxRate * getTotal());
    }

    string generateReciept()
    {
        string reciept = "";

        reciept += "==================================\n";
        reciept += "             RECIEPT\n";
        reciept += "==================================\n";

        reciept += "Name\tCost\n";

        for (int i = 0; i < numDessertItems; i++)
        {
            reciept += (dessertItems[i]->getName() + "\t" + to_string((int)(dessertItems[i]->getCost() / 100)) + " Dollars and " + to_string((int)(dessertItems[i]->getCost() % 100)) + " Cents" + "\n");
        }

        reciept += ("\nTax: " + to_string((int)(getTotalTax() / 100)) + " Dollars and " + to_string((int)(getTotalTax() % 100)) + " Cents" + "\n");
        reciept += ("Total: " + to_string((int)(getTotal() / 100)) + " Dollars and " + to_string((int)(getTotal() % 100)) + " Cents" + "\n");

        return reciept;
    }
};

int main()
{
    Checkout checkout;

    Sundae sundae("Sundae", 45, 300);
    Cookie cookie("Cookie", 5, 100);
    Candy candy("Candy", 3.0, 12.0);

    DessertItem *s = &sundae;
    DessertItem *c = &cookie;
    DessertItem *can = &candy;

    checkout.addDessertItemToRegister(s);
    checkout.addDessertItemToRegister(c);
    checkout.addDessertItemToRegister(can);

    cout << checkout.generateReciept() << endl;
}