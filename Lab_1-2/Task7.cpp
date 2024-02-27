#include <iostream>

using namespace std;

int main()
{
    int n, sum, pairsTop = -1;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter sum: ";
    cin >> sum;

    int *array = new int[n], *pairs = new int[2 * n];

    // input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element[" << i + 1 << "]: ";
        cin >> array[i];
    }

    // finding pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i] + array[j] == sum)
            {
                pairsTop++;
                pairs[pairsTop] = array[i];
                pairsTop++;
                pairs[pairsTop] = array[j];
            }
        }
    }

    // Sort the pairs
    for (int i = 0; i <= pairsTop; i++)
    {
        for (int j = 0; j <= pairsTop; j++)
        {
            if (pairs[i] > pairs[j])
            {
                int temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }

    // Printing
    cout << pairsTop << endl;
    cout << "Pairs: \n{";
    for (int i = 0; i <= pairsTop; i++)
    {
        cout << pairs[i] << ", ";
    }
    cout << "\b\b}";
}