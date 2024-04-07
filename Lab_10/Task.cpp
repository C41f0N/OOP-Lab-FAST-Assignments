#include <iostream>

using namespace std;

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
};

class Staff : public Employee
{
protected:
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
};

int main()
{

    Course courseList[4] = {
        Course("1111", "Computer Science", "2"),
        Course("1111", "Electrical Engineering", "2"),
        Course("1111", "Management Science", "2")};

    Faculty facultyMember("Sarim", "CEO", "Computer Science", 10000000, 37);

    facultyMember.assignCourse(courseList, 4);

    facultyMember.printSalary();
}