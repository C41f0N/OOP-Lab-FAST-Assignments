#include <iostream>

using namespace std;

class Burger
{
    float price;
    string ingredient1, ingredient2, ingredient3, taste;

public:
    Burger(
        float price,
        string ingredient1,
        string ingredient2,
        string ingredient3,
        string taste)
        : price(price),
          ingredient1(ingredient1),
          ingredient2(ingredient2),
          ingredient3(ingredient3),
          taste(taste) {}

    float getCost()
    {
        return price;
    }

    void setCost(float cost)
    {
        price = cost;
    }

    void display()
    {
        cout << endl
             << "Details======" << endl;
        cout << "Price: " << price << endl;
        cout << "Ingredient1: " << ingredient1 << endl;
        cout << "Ingredient2: " << ingredient2 << endl;
        cout << "Ingredient3: " << ingredient3 << endl;
        cout << "Taste: " << taste << endl;
    }
};

class ChickenBurger : public Burger
{
    bool extraCheese;

public:
    ChickenBurger() : Burger(1000, "Chicken Patty", "Sauces", "Cheese", "mild"), extraCheese(false)
    {
    }

    void addExtraCheese()
    {
        extraCheese = true;
        setCost(getCost() + 500);
    }
};

class BeefBurger : public Burger
{
    bool extraCheese;

public:
    BeefBurger() : Burger(1500, "Beef", "Sauces", "Cheese", "mild"), extraCheese(false) {}

    void addExtraCheese()
    {
        extraCheese = true;
        setCost(getCost() + 500);
    }
};

int main()
{
    bool ordering = true;
    int option;

    while (ordering)
    {
        // Show menu
        cout << "===============================" << endl;
        cout << "=========== M E N U ===========" << endl;
        cout << "===============================" << endl
             << endl;

        cout << "Option\tName\t\tPrice" << endl;
        cout << "[1]\tChicken Burger\t" << 1000 << endl;
        cout << "[2]\tBeef Burger\t" << 1500 << endl;
        cout << ": ";
        cin >> option;

        // Create burger accordingly
        if (option == 1)
        {
            ChickenBurger chickenBurger;

            cout << "Do you want extra cheese? (0 for no, 1 for yes) : ";
            cin >> option;

            if (option == 1)
            {
                chickenBurger.addExtraCheese();
            }

            cout << "Do you want to finish ordering? (0 for no, 1 for yes) : ";
            cin >> option;

            if (option == 1)
            {
                ordering = false;
                chickenBurger.display();
            }
        }
        else if (option == 2)
        {
            BeefBurger beefBurger;

            cout << "Do you want extra cheese? (0 for no, 1 for yes) : ";
            cin >> option;

            if (option == 1)
            {
                beefBurger.addExtraCheese();
            }

            cout << "Do you want to finish ordering? (0 for no, 1 for yes) : ";
            cin >> option;

            if (option == 1)
            {
                ordering = false;
                beefBurger.display();
            }
        }
    }
}