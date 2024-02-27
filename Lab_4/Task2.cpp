#include <iostream>

using namespace std;

class Number
{

    int num, result;

public:
    Number(int num)
    {
        this->num = num;
    }

    bool isWhole()
    {
        return ((float)(num % 1) == 0);
    }

    bool isPositive()
    {
        return num > 0;
    }

    void factorial()
    {
        if (isWhole() && isPositive())
        {
            result = 1;

            for (int i = 1; i <= num; i++)
            {
                result *= i;
            }
        }
    }

    void display()
    {
        cout << "Number: " << num << endl
             << "Factorial: " << result << endl;
    }
};

int main()
{
    Number myNum(6);

    myNum.factorial();
    myNum.display();
}