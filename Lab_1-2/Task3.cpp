#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void printReverse(string array, int len)
{
    char temp;

    for (int i = 0; i < floor(len / 2); i++)
    {
        temp = array[i];
        array[i] = array[len - i - 1];
        array[len - i - 1] = temp;
    }

    cout << array;
}

int main()
{
    string array;

    cout << "Enter a string: ";
    cin >> array;

    // Print after reverse
    printReverse(array, array.length());
}