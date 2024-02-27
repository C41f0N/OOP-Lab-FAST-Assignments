#include <iostream>

using namespace std;

bool equalsIgnoreCase(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (tolower(a[i]) != tolower(b[i]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string first, second;

    cout << "Enter a string: ";
    cin >> first;

    cout << "Enter a string of same length: ";
    cin >> second;

    if (equalsIgnoreCase(first, second))
    {
        cout << "Are the same.";
    }
    else
    {
        cout << "Are not the same.";
    }
}