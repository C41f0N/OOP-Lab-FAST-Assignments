#include <iostream>
using namespace std;

void strReverse(string str)
{
    string temp = " ";
    cout << "Reversed string: ";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        temp += str[i];
    }

    str = temp;

    for (int i = 0; i < str.length(); i++)
        cout << str[i];
}

int main()
{
    string str;
    cout << "Enter any string: ";
    cin >> str;

    cout << "Original string: ";
    for (int i = 0; i < str.length(); i++)
        cout << str[i];

    strReverse(str);
}