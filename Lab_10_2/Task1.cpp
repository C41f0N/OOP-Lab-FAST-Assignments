#include <iostream>
#include <string>

using namespace std;

class Complex
{
    float real, imaginary;

    friend ostream &operator<<(ostream &os, Complex &obj);
    friend Complex &operator>>(istream &is, Complex &obj);

public:
    Complex(float real, float imaginary) : real(real), imaginary(imaginary)
    {
    }

    Complex operator+(const Complex comp)
    {
        Complex compRes(this->real + comp.real, this->imaginary + comp.imaginary);

        return compRes;
    }

    Complex operator-()
    {
        Complex compRes(this->real * -1, this->imaginary * -1);

        return compRes;
    }
};

ostream &operator<<(ostream &os, Complex &obj)
{
    os << obj.real;

    if (obj.imaginary != 0)
    {

        if (obj.imaginary < 0)
        {
            os << " - " << obj.imaginary * -1 << "i";
        }
        else
        {
            os << " + " << obj.imaginary << "i";
        }
    }

    return os;
}

Complex &operator>>(istream &is, Complex &obj)
{
    string input, inputReal = "", inputImaginary = "";
    getline(is, input);

    // Getting real part of string
    int i = 0;
    while (input[i] != ' ')
    {
        inputReal += input[i];
        i++;
    }

    i++;

    // Getting imaginary part of string
    while (i < input.length())
    {
        inputImaginary += input[i];
        i++;
    }

    // Coverting string and setting it in Complex
    obj.real = stof(inputReal);
    obj.imaginary = stof(inputImaginary);

    return obj;
}

int main()
{
    Complex complex1(9.98, -1);
    Complex complex2(100, -2);
    Complex complex3(1, 1);

    cin >> complex3;
    complex3 = -complex3;

    complex1 = complex1 + complex2;

    cout << complex1 << endl;
    cout << complex2 << endl;
    cout << complex3 << endl;
}