#include <iostream>

using namespace std;

class Faculty;

class Employee
{
protected:
    string name, designation, department;
    int salary;

public:
    Employee(
        string name,
        string designation,
        string department,
        int salary)
        : name(name),
          designation(designation),
          department(department),
          salary(salary) {}

    bool verify(string department)
    {
        return this->department == department;
    }

    int operator++()
    {
        return this->salary * 1.1;
    }
};

class Staff : public Employee
{
protected:
    friend int operator+(const Staff staff, const Faculty faculty);
    int overtimeHours;

public:
    Staff(
        string name,
        string designation,
        string department,
        int salary,
        int overtimeHours)
        : Employee(
              name,
              designation,
              department,
              salary),
          overtimeHours(overtimeHours)
    {
    }

    bool verify(string department)
    {
        return this->department == department;
    }

    bool verify(int lowerBound, int upperBound)
    {
        return this->salary > lowerBound && this->salary < upperBound;
    }
};

class Course
{
    string code, name, creditHours;
    bool assigned;

public:
    Course() {}

    Course(
        string code,
        string name,
        string creditHours)
        : code(code),
          name(name),
          creditHours(creditHours),
          assigned(false) {}

    string getCode()
    {
        return this->code;
    }

    string getName()
    {
        return this->name;
    }

    string getCreditHours()
    {
        return this->creditHours;
    }
};

class Faculty : public Employee
{
protected:
    int workingHours, assignedCourseCount;
    Course courseList[10];

public:
    friend int operator+(const Staff staff, const Faculty faculty);
    Faculty(
        string name,
        string designation,
        string department,
        int salary,
        int workingHours)
        : Employee(
              name,
              designation,
              department,
              salary),
          workingHours(workingHours),
          assignedCourseCount(0)
    {
    }

    void assignCourse(Course courseList[], int length)
    {
        char targetChar;

        if (this->department == "Computer Science")
        {
            targetChar = 'C';
        }
        else if (this->department == "Management Science")
        {
            targetChar = 'M';
        }
        else if (this->department == "Electrical Engineering")
        {
            targetChar = 'E';
        }

        // If valid targetChar, add course
        if (
            targetChar == 'C' ||
            targetChar == 'M' ||
            targetChar == 'E')
        {

            // checking for valid course
            for (int i = 0; i < length; i++)
            {
                if (courseList[i].getName()[0] == targetChar)
                {
                    // add course
                    this->courseList[assignedCourseCount] = courseList[i];
                    assignedCourseCount++;

                    // add credit hours
                    workingHours += stoi(courseList[i].getCreditHours());

                    if (workingHours > 12)
                    {
                        cout << "[WARNING] Working hours exceeded 12." << endl;
                    }

                    break;
                }
            }
        }
    }

    void printSalary()
    {
        cout << "Salary: ";

        if (workingHours <= 36)
        {
            cout << salary << endl;
        }
        else
        {
            salary += (1000 * (workingHours - 36));
            cout << salary << endl;
        }
    }

    Faculty operator++()
    {
        Faculty updatedFaculty("", "", "", 0, 0);

        if (this->designation == "instructor")
        {
            updatedFaculty = Faculty(
                this->name,
                "assistant",
                this->department,
                this->salary * 1.2,
                this->workingHours);
        }
        else if (this->designation == "lecturer")
        {
            updatedFaculty = Faculty(
                this->name,
                "professor",
                this->department,
                this->salary * 1.2,
                this->workingHours);
        }
        else
        {
            updatedFaculty = Faculty(
                this->name,
                this->designation,
                this->department,
                this->salary * 1.2,
                this->workingHours);
        }

        return updatedFaculty;
    }
};

int operator+(const Staff staff, const Faculty faculty)
{
    return staff.salary + faculty.salary;
}

int main()
{
    Employee ob1("Ali", "Lecturer", "Electrical Engineering", 150000);
    int increased10percentage = (++ob1);
    cout << increased10percentage << endl;

    Faculty ob2("Jawed", "Instructor", "Computer Science", 100000, 0);
    ob2 = ++ob2;
    ob2.printSalary();

    Faculty ob3("Naveed", "Instructor", "Management Science", 100000, 0);
    Staff ob4("Majeed", "Instructor", "Computer Science", 100000, 0);
    int sumOfSalaries = ob4 + ob3;
    cout << sumOfSalaries << endl;
}