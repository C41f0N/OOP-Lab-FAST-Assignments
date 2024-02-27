#include <iostream>
#include <math.h>

using namespace std;

int armstrong(string inputNumber)
{
    int total = 0, number = 0;

    for (int i = 0; i < inputNumber.length(); i++)
    {

        total += ceil(pow((inputNumber[i] - '0'), 3));
        number += ceil(pow(10, inputNumber.length() - i - 1) * (inputNumber[i] - '0'));
    }

    return number == total;
}

int main()
{
    string input;

    cout << "Enter Armstrong Number: ";
    cin >> input;

    if (armstrong(input))
    {
        cout << "Is an Armstrong Number.";
    }
    else
    {
        cout << "Is not an Armstrong Number.";
    }
}