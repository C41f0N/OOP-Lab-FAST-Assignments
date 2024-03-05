#include <iostream>

using namespace std;

class Pizza
{
    string size;
    int numCheeseToppings, numPepperoniToppings, numHamToppings;

public:
    Pizza(
        string size,
        int numCheeseToppings,
        int numPepperoniToppings,
        int numHamToppings)
        : size(size),
          numCheeseToppings(numCheeseToppings),
          numPepperoniToppings(numPepperoniToppings),
          numHamToppings(numHamToppings) {}

    Pizza(Pizza &pizza)
    {
        this->size = pizza.size;
        this->numCheeseToppings = pizza.numCheeseToppings;
        this->numHamToppings = pizza.numHamToppings;
        this->numPepperoniToppings = pizza.numPepperoniToppings;
    }

    string getSize()
    {
        return this->size;
    }

    void setSize(string size)
    {
        this->size = size;
    }

    int getNumCheeseToppings()
    {
        return this->numCheeseToppings;
    }

    int getNumPepperoniToppings()
    {
        return this->numPepperoniToppings;
    }

    int getNumHamToppings()
    {
        return this->numHamToppings;
    }

    void setNumCheeseToppings(int numCheeseToppings)
    {
        this->numCheeseToppings = numCheeseToppings;
    }

    void setNumPepperoniToppings(int numPepperoniToppings)
    {
        this->numPepperoniToppings = numPepperoniToppings;
    }

    void setNumHamToppings(int numHamToppings)
    {
        this->numHamToppings = numHamToppings;
    }

    float costPizza()
    {
        float cost;

        // Set initial cost
        if (this->size == "small")
        {
            cost = 1000;
        }
        else if (this->size == "medium")
        {
            cost = 1200;
        }
        else if (this->size == "large")
        {
            cost = 1400;
        }

        // Add toppings cost
        cost += (float)(numCheeseToppings * 200) + (numHamToppings * 200) + (numPepperoniToppings * 200);

        return cost;
    }

    string getDescription()
    {
        return this->size;
    }

    void display()
    {
        cout << "A " << this->size << " pizza with " << this->numCheeseToppings << " cheese, " << this->numPepperoniToppings << " pepperoni and " << this->numHamToppings << " ham toppings should cost a total of " << costPizza() << "." << endl;
    }
};

int main()
{
    Pizza pizza1("small", 1, 2, 3);
    Pizza pizza2("large", 1, 1, 4);
    Pizza pizza3("medium", 4, 2, 7);
    Pizza pizza4("small", 1, 2, 2);
    Pizza pizza5("large", 1, 4, 3);

    pizza1.display();

    char choice;
    cout << "Do you want to update this order? (Y/n): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        string size;
        int numCheese, numPepperoni, numHam;

        // Get updated values
        cout << "Enter new size: ";
        cin >> size;

        cout << "Enter new cheese toppings: ";
        cin >> numCheese;

        cout << "Enter new pepperoni toppings: ";
        cin >> numPepperoni;

        cout << "Enter new ham toppings: ";
        cin >> numHam;

        // Backup old data
        Pizza oldPizza1(pizza1);

        // Replace pizza1
        pizza1.setSize(size);
        pizza1.setNumCheeseToppings(numCheese);
        pizza1.setNumHamToppings(numHam);
        pizza1.setNumPepperoniToppings(numPepperoni);

        // Display both new and old
        cout << endl
             << endl
             << "Old Order:" << endl;
        oldPizza1.display();

        cout << endl
             << endl
             << "New Order:" << endl;
        pizza1.display();

        // Ask which one the user wants
        cout << "Do you want the old one or the new one? (O/N): ";
        cin >> choice;

        if (choice == 'O' || choice == 'o')
        {
            // Restore old order
            pizza1.setSize(oldPizza1.getSize());
            pizza1.setNumCheeseToppings(oldPizza1.getNumCheeseToppings());
            pizza1.setNumHamToppings(oldPizza1.getNumHamToppings());
            pizza1.setNumPepperoniToppings(oldPizza1.getNumPepperoniToppings());
        }
    }

    cout << endl
         << endl
         << "Other Pizzas:" << endl;

    pizza2.display();
    pizza3.display();
    pizza4.display();
    pizza5.display();
}