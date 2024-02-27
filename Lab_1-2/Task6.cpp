#include <iostream>

using namespace std;

int mod(int n, int m)
{
    if (n >= m)
    {
        return mod(n - m, m);
    }
    else
    {
        return n;
    }
}

int main()
{
    int n, m;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    cout << mod(n, m);
}