#include <iostream>

using namespace std;

// Employee Base Class
class Employee
{

protected:
    float yearlySalary;
    int hoursWorkedPerMonth;

public:
    Employee(int hoursWorkedPerMonth, float yearlySalary = 40000)
    {
        this->yearlySalary = yearlySalary;
        this->hoursWorkedPerMonth = hoursWorkedPerMonth;
    }

    void calculateSalary(float yearlySalary = 40000)
    {
        this->yearlySalary = yearlySalary + (float)(150 * hoursWorkedPerMonth);
    }

    void printSalary()
    {
        cout << "Salary: " << yearlySalary << endl;
    }
};

// Lawyer Class
class Lawyer : protected Employee
{
public:
    Lawyer(int hoursWorkedPerMonth) : Employee(hoursWorkedPerMonth) {}

    void sue()
    {
        cout << "Suing." << endl
             << endl;
    }

    void calculateLawyerSalary()
    {
        calculateSalary();
    }

    void printLawyerSalary()
    {
        printSalary();
    }
};

// Marketer Class
class Marketer : protected Employee
{
public:
    Marketer(int hoursWorkedPerMonth) : Employee(hoursWorkedPerMonth, 50000) {}

    void advertise()
    {
        cout << "Advertising" << endl
             << endl;
    }

    void extraPayMarketers()
    {
        calculateSalary(50000);
    }

    void printMarketerSalary()
    {
        printSalary();
    }
};

class Secretary : protected Employee
{
    int leavesLeft;

public:
    Secretary(int hoursWorkedPerMonth) : leavesLeft(14), Employee(hoursWorkedPerMonth, 45000) {}

    void takeDictation()
    {
        cout << "Taking Dictation" << endl
             << endl;
    }

    void extraPaySecrataries()
    {
        calculateSalary(45000);
    }

    void printSecretarySalary()
    {
        printSalary();
    }

    void takeLeave(int days)
    {
        this->leavesLeft -= days;
    }

    void availAllLeaves()
    {
        this->yearlySalary += (this->leavesLeft * (5000 / 14));
        this->leavesLeft = 0;
    }
};

class LegalSecretary : public Secretary
{
public:
    LegalSecretary(int hoursWorkedPerMonth) : Secretary(hoursWorkedPerMonth) {}

    void prepareLegalDocuments()
    {
        cout << "Preparing Legal Documents" << endl
             << endl;
    }
};

int main()
{
    Lawyer laywer(23);
    laywer.calculateLawyerSalary();
    laywer.printLawyerSalary();
    laywer.sue();

    Marketer marketer(45);
    marketer.extraPayMarketers();
    marketer.printMarketerSalary();
    marketer.advertise();

    Secretary secretary(12);
    secretary.extraPaySecrataries();
    secretary.printSecretarySalary();
    secretary.takeDictation();

    LegalSecretary legalSecretary(123);
    legalSecretary.extraPaySecrataries();
    legalSecretary.printSecretarySalary();
    legalSecretary.prepareLegalDocuments();
}