#include <iostream>
#include <ctime>
#include <ctime>

using namespace std;

class Person
{

protected:
    string name, number, gender;

    Person(string name,
           string number,
           string gender)
        : name(name),
          number(number),
          gender(gender) {}
};

class PasswordGenerator : public Person
{
public:
    PasswordGenerator(
        string name,
        string number,
        string gender)
        : Person(name,
                 number,
                 gender) {}

    void generatePassword()
    {
        int minimumLength;
        int numberOfSpecialCharacters;
        int numberOfDigits;
        string pass = "";

        cout
            << "Enter minimumLength: ";
        cin >> minimumLength;

        cout << "Enter numberOfSpecialCharacters: ";
        cin >> numberOfSpecialCharacters;

        cout << "Enter numberOfDigits: ";
        cin >> numberOfDigits;

        string specialCharacters = "\"#$%&’()*+,-./:;<=>?@[\\]ˆ_‘{|}˜";

        // Generating

        // Adding letters
        for (int i = 0; i < minimumLength - numberOfSpecialCharacters - numberOfDigits; i++)
        {
            pass += name[rand() % name.length()];
        }

        // Adding special chars
        for (int i = 0; i < numberOfSpecialCharacters; i++)
        {
            pass += specialCharacters[rand() % specialCharacters.length()];
        }

        // Adding numbers
        for (int i = 0; i < numberOfDigits; i++)
        {
            pass += number[rand() % number.length()];
        }

        cout << "New password: " << pass;
    }
};

int main()
{
    srand(time(NULL));

    PasswordGenerator passwordGenerator("Shaheer", "03001234567", "Male");

    passwordGenerator.generatePassword();
}