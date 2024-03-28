#include <iostream>
#include <string>

using namespace std;

class Product
{

    string name, barcode;

public:
    Product(
        string name = "product name",
        string barcode = "0 000 0000 0")
        : name(name),
          barcode(barcode) {}

    void scanner()
    {
        cout << "Enter code: ";
        getline(cin, this->barcode);
    }

    void printer()
    {
        cout << this->barcode << endl;
    }

    void setCode(string barcode)
    {
        this->barcode = barcode;
    }

    string getCode()
    {
        return this->barcode;
    }
};

class PrepackedFood : public Product
{
    float unitPrice;

public:
    PrepackedFood(
        string name = "product name",
        string barcode = "0 000 0000 0",
        float unitPrice = 0.0)
        : Product(name, barcode), unitPrice(unitPrice) {}

    void setUnitPrice(float unitPrice)
    {
        this->unitPrice = unitPrice;
    }

    float getUnitPrice()
    {
        return this->unitPrice;
    }

    void printer()
    {
        Product::printer();
        cout << this->getUnitPrice() << endl;
    }

    void scanner()
    {
        Product::scanner();

        cout << "Enter Unit Price: ";
        cin >> unitPrice;
    }
};

class FreshFood : public Product
{
    float pricePerKilo, weight;

public:
    FreshFood(
        string name = "product name",
        string barcode = "0 000 0000 0",
        float pricePerKilo = 0.0,
        float weight = 0.0)
        : Product(name, barcode), pricePerKilo(pricePerKilo), weight(weight) {}

    void setPricePerKilo(float pricePerKilo)
    {
        this->pricePerKilo = pricePerKilo;
    }

    float getPricePerKilo()
    {
        return this->pricePerKilo;
    }

    void setWeight(float weight)
    {
        this->weight = weight;
    }

    float getWeight()
    {
        return this->weight;
    }

    void printer()
    {
        Product::printer();

        cout << this->getPricePerKilo() << endl;
    }

    void scanner()
    {

        Product::scanner();

        cout << "Enter Price Per Kilo: ";
        cin >> pricePerKilo;

        cout << "Enter Weight: ";
        cin >> weight;
    }
};

int main()
{

    FreshFood f1("Raddish", "1 213 1266 9", 4.5), f2, f3;
    PrepackedFood p1("Deer Meat", "2 235 6753 8", 9.0), p2, p3;

    // Parametrized
    p1.printer();
    f1.printer();

    // Checking for default values
    p2.scanner();
    p2.printer();

    f2.scanner();
    f2.printer();

    // Setter getters
    f3.setCode("2 222 2222 2");
    f3.setPricePerKilo(23);
    f3.setWeight(23);

    cout << f3.getCode() << endl;
    cout << f3.getPricePerKilo() << endl;
    cout << f3.getWeight() << endl;

    p3.setCode("2 522 2222 2");
    p3.setUnitPrice(24);

    cout << p3.getCode() << endl;
    cout << p3.getUnitPrice() << endl;

    return 0;
}