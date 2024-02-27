#include <iostream>

using namespace std;

int count = 0;

class Product
{
    int pro_code;
    float pro_price;

public:
    Product()
    {
    }

    int getCode()
    {
        return pro_code;
    }

    float getPrice()
    {
        return pro_price;
    }

    void getProduct()
    {
        count++;
        cout << "Enter Product Code: ";
        cin >> pro_code;

        cout << "Enter Product Price: ";
        cin >> pro_price;
    }
};

void displaySum(Product products[])
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += products[i].getPrice();
    }

    cout << "Product Sum: " << sum << endl;
}

void display(Product products[])
{
    cout << "Code\tPrice" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << products[i].getCode() << "\t" << products[i].getPrice() << endl;
    }
}

int main()
{
    Product products[100];
    int productsTop = -1;

    int running = true;
    int choice;

    while (running)
    {
        cout << endl
             << endl
             << endl
             << "[1] Add a product" << endl;
        cout << "[2] Display product total" << endl;
        cout << "[3] Display all products" << endl;
        cout << "[4] Quit" << endl
             << endl;
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            productsTop++;
            products[productsTop].getProduct();
            break;

        case 2:
            displaySum(products);
            break;

        case 3:
            display(products);
            break;
        case 4:
            running = false;
            break;

        default:
            break;
        }
    }
}