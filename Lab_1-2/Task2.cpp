#include <iostream>
using namespace std;

void newSeries(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        array[i] = array[i] + array[i + 1];
    }
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element[" << i + 1 << "]: ";
        cin >> array[i];
    }

    // Printing array before
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ", ";
    }
    cout << "\b\b}" << endl;

    newSeries(array, n);
    if (n % 2 == 0)
        n -= 1;

    // Printing array after
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ", ";
    }
    cout << "\b\b}" << endl;
}