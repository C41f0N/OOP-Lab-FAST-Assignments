#include <iostream>

using namespace std;

struct Invoice
{
    string partNumber, description;
    int quantity;
    float price;
};

struct Invoice invoice
{
    "0000",
        "No Description",
        0,
        0.0,
};

void setPartNumber(string partNumber)
{
    invoice.partNumber = partNumber;
}

void setPartDescription(string partDescription)
{
    invoice.description = partDescription;
}

void setPartPrice(float price)
{
    invoice.price = price;
}

void setPartQuantity(float quanitity)
{
    invoice.quantity = quanitity;
}

void increaseQuantityBy(int increase)
{
    invoice.quantity += increase;
}

void decreaseQuantityBy(int decrease)
{
    invoice.quantity -= decrease;
    if (invoice.quantity < 0)
        invoice.quantity = 0;
}

void printInvoice()
{
    int x;
    cout << endl;
    cout << "========================" << endl;
    cout << "         INVOICE" << endl;
    cout << "========================" << endl;
    cout << "Part Number:\t\t" << invoice.partNumber << endl;
    cout << "Quantity:\t\t" << invoice.quantity << endl;
    cout << "Price:\t\t\t" << invoice.price << "$" << endl;
    cout << "Part Description: " << invoice.description << endl;

    cout << "Enter 0 to continue...";
    cin >> x;
}

void printMenu()
{
    cout << "==============================" << endl;
    cout << "        INVOICE MAKER" << endl;
    cout << "==============================" << endl;
    cout << "Select an option: " << endl;
    cout << "[1] Set Part Number" << endl;
    cout << "[2] Set Part Description" << endl;
    cout << "[3] Set Part Price" << endl;
    cout << "[4] Set Part Quantity" << endl;
    cout << "[5] Increase Quantity By" << endl;
    cout << "[6] Decrease Quantity By" << endl;
    cout << "[7] Print Invoice" << endl;
    cout << "[8] Exit" << endl;
    cout << endl
         << ": ";
}

int main()
{
    bool running = true;
    int option = 0;

    string partNumber, description;
    int quantity, increase, decrease;
    float price;

    while (running)
    {
        printMenu();
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter Part Number: ";
            cin >> partNumber;
            setPartNumber(partNumber);
            break;

        case 2:
            cout << "Enter Part Description: ";
            cin >> description;
            setPartDescription(description);
            break;

        case 3:
            cout << "Enter Part Price: ";
            cin >> price;
            setPartPrice(price);
            break;

        case 4:
            cout << "Enter Part Quantity: ";
            cin >> quantity;
            setPartPrice(quantity);
            break;

        case 5:
            cout << "Enter the amount you want to increase the quantity by: ";
            cin >> increase;
            increaseQuantityBy(increase);
            break;

        case 6:
            cout << "Enter the amount you want to decrease the quantity by: ";
            cin >> decrease;
            decreaseQuantityBy(decrease);
            break;

        case 7:
            printInvoice();
            break;

        case 8:
            running = false;
            break;

        default:
            cout
                << "[-] Invalid option selected.";
            break;
        }
    }
}