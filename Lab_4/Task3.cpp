#include <iostream>

using namespace std;

class Employee
{
    int empCode;
    string empName;

public:
    Employee() {}

    Employee(int empCode)
    {
        this->empCode = empCode;
    }

    Employee(string empName)
    {
        this->empName = empName;
    }

    void setEmpCode(int empCode)
    {
        this->empCode = empCode;
    }

    int getEmpCode()
    {
        return empCode;
    }

    void setEmpName(string empName)
    {
        this->empName = empName;
    }

    string getEmpName()
    {
        return empName;
    }

    void display()
    {
        cout << "Employee Name: " << getEmpName() << endl;
        cout << "Employee Code: " << getEmpCode() << endl
             << endl;
    }
};

int main()
{
    Employee employees[10];
    int employeesTop = -1;
    bool accepting = true;
    string employeeName;
    int employeeCode;

    // Take input
    while (accepting != 0 && employeesTop < 9)
    {
        employeesTop++;
        cout << "Enter Employee " << employeesTop << "'s Name: ";
        cin >> employeeName;

        cout << "Enter Employee " << employeesTop << "'s Code: ";
        cin >> employeeCode;

        employees[employeesTop].setEmpCode(employeeCode);
        employees[employeesTop].setEmpName(employeeName);

        cout << endl
             << "Enter 0 if you want to stop, 1 to go on: ";
        cin >> accepting;
    }

    // Show Employee Data
    cout << endl
         << "Printing Employee Data:" << endl;
    for (int i = 0; i <= employeesTop; i++)
    {
        employees[i].display();
    }
}