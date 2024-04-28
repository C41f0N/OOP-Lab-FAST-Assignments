#include <iostream>

using namespace std;

class Poly
{
    double a, b, c;
    friend ostream &operator<<(ostream &os, Poly &obj);

public:
    Poly(){};

    Poly(double a, double b, double c) : a(a), b(b), c(c) {}

    Poly operator+(const Poly poly)
    {
        Poly polyRes(this->a + poly.a, this->b + poly.b, this->c + poly.c);

        return polyRes;
    }
};

ostream &operator<<(ostream &os, Poly &obj)
{
    if (obj.a != 0)
    {
        os << obj.a << "x^2";
    }

    if (obj.b != 0)
    {
        if (obj.b < 0)
        {
            os << " - ";
        }
        else
        {
            os << " + ";
        }

        os << obj.b << "x";
    }

    if (obj.c != 0)
    {
        if (obj.c < 0)
        {
            os << " - ";
        }
        else
        {
            os << " + ";
        }
        os << obj.c;
    }

    return os;
}

int main()
{
    Poly q1(3, 4, -2);
    Poly q2(-4, 0, 10);

    cout << "q1: " << q1 << endl;
    cout << "q2: " << q2 << endl;

    Poly q3 = q1 + q2;

    cout << "Sum if q1 and q2: " << q3 << endl;
}