#include <iostream>

using namespace std;

class Stock
{
    string symbol, companyName;
    double price;
    int availableQuantity, maxQuantityPerInvestor, stockCategoryQuantity;

public:
    Stock() {}
    Stock(
        string symbol,
        string companyName,
        double price,
        int availableQuantity,
        int maxQuantityPerInvestor,
        int stockCategoryQuantity)
        : symbol(symbol),
          companyName(companyName),
          price(price),
          availableQuantity(availableQuantity),
          maxQuantityPerInvestor(maxQuantityPerInvestor),
          stockCategoryQuantity(stockCategoryQuantity) {}

    string getSymbol()
    {
        return this->symbol;
    }

    string getCompanyName()
    {
        return this->companyName;
    }

    void reduceQuantity(int quantity)
    {
        this->availableQuantity -= quantity;
    }

    double getPrice()
    {
        return this->price;
    }

    int getAvailableQuanity()
    {
        return availableQuantity;
    }

    int getMaxQuantityPerInvestor()
    {
        return maxQuantityPerInvestor;
    }

    virtual bool isEligibleToBuy(int purchaseQuantity)
    {
        return false;
    }

    void displayInfo()
    {

        cout << "Symbol: " << symbol << endl;
        cout << "Company Name: " << companyName << endl;
        cout << "Price: " << price << endl;
        cout << "Available Quantity: " << availableQuantity << endl;
        cout << "Max Quantity Per Investor: " << maxQuantityPerInvestor << endl;
        cout << "Stock Category Quantity: " << stockCategoryQuantity << endl;
    }
};

class PharmaStock : public Stock
{

public:
    PharmaStock(
        string symbol,
        string companyName,
        double price,
        int availableQuantity,
        int maxQuantityPerInvestor,
        int stockCategoryQuantity)
        : Stock(
              symbol,
              companyName,
              price,
              availableQuantity,
              maxQuantityPerInvestor,
              stockCategoryQuantity) {}

    bool isEligibleToBuy(int purchaseQuantity)
    {
        return purchaseQuantity <= getAvailableQuanity();
    }
};

class TechStock : public Stock
{

public:
    TechStock(
        string symbol,
        string companyName,
        double price,
        int availableQuantity,
        int maxQuantityPerInvestor,
        int stockCategoryQuantity)
        : Stock(
              symbol,
              companyName,
              price,
              availableQuantity,
              maxQuantityPerInvestor,
              stockCategoryQuantity) {}

    bool isEligibleToBuy(int purchaseQuantity)
    {
        return purchaseQuantity <= getAvailableQuanity();
    }
};

class Market
{
    int numStocks;
    Stock *stocks;

public:
    Market() : numStocks(0) {}

    void addStocks(Stock *stock)
    {
        Stock *newStocks = new Stock[numStocks + 1];
        ;

        // Copy old data
        for (int i = 0; i < numStocks; i++)
        {
            newStocks[i] = stocks[i];
        }

        newStocks[numStocks] = *stock;

        if (numStocks > 0)
        {
            delete[] stocks;
        }

        stocks = newStocks;
        numStocks++;
    }

    void tradeStocks()
    {
        int quantity, stocksTraded = 0;
        for (int i = 0; i < numStocks; i++)
        {
            Stock stock = stocks[i];
            quantity = min(stock.getAvailableQuanity(), stock.getMaxQuantityPerInvestor());
            stocksTraded += quantity;
            stock.reduceQuantity(quantity);
        }

        cout << endl
             << stocksTraded << " number of stocks traded." << endl;
    }
};

int main()
{
    Market market;

    TechStock *stock1 = new TechStock("T", "Sarim Tech", 900, 120, 100, 20);
    TechStock *stock2 = new TechStock("t", "Sarim AI", 900, 130, 300, 20);
    TechStock *stock3 = new TechStock("s", "Sarim Data", 900, 13, 50, 20);

    PharmaStock *stock4 = new PharmaStock("P", "Someone Medicine", 100, 100, 23, 100);
    PharmaStock *stock5 = new PharmaStock("p", "Someone Care", 100, 140, 53, 100);
    PharmaStock *stock6 = new PharmaStock("w", "Someone Health", 100, 130, 23, 100);

    market.addStocks(stock1);
    market.addStocks(stock2);
    market.addStocks(stock3);
    market.addStocks(stock4);
    market.addStocks(stock5);
    market.addStocks(stock6);

    market.tradeStocks();
}