#include <iostream>

using namespace std;

class Book
{
private:
    int bookNo;
    string bookTitle;
    float price;

    float totalCost(int n)
    {
        return (float)price * n;
    }

public:
    void input(int bookNoP, string bookTitleP, float priceP)
    {
        bookNo = bookNoP;
        bookTitle = bookTitleP;
        price = priceP;
    }

    void purchase()
    {
        int quantity;

        cout << endl
             << "Enter the quantity: ";
        cin >> quantity;

        cout << "Total Cost: " << totalCost(quantity) << endl;
    }
};

int main()
{
    Book myBook;

    myBook.input(1234, "Subtle Art of not Caring", 10.7);
    myBook.purchase();
}