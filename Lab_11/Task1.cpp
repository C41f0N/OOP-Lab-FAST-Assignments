#include <iostream>

using namespace std;

class Faculty;
class Registrar;

class User
{
protected:
    string username, password;
    bool loggedIn;

public:
    User(string username,
         string password)
        : username(username),
          password(password),
          loggedIn(false) {}

    virtual bool login(string username, string password) = 0;
    virtual void logout() = 0;
};

class Course
{
protected:
    string code, description, section;
    int creditHours;
    float costPerCredit;

public:
    Course(
        string code,
        string description,
        string section,
        int creditHours,
        float costPerCredit)
        : code(code),
          description(description),
          section(section),
          creditHours(creditHours),
          costPerCredit(costPerCredit) {}

    string getCode()
    {
        return this->code;
    }

    string getDescription()
    {
        return this->description;
    }

    string getSection()
    {
        return this->section;
    }

    int getCreditHours()
    {
        return this->creditHours;
    }

    float getCostPerCredit()
    {
        return this->costPerCredit;
    }
};

class Student : public User
{
protected:
    string studentId, phoneNumber;
    Course **registeredCourses;
    int numCourses;

    friend Faculty;
    friend Registrar;

public:
    Student(
        string username,
        string password,
        string studentId,
        string phoneNumber)
        : User(username, password),
          studentId(studentId),
          phoneNumber(phoneNumber),
          numCourses(0) {}

    bool login(string username, string password)
    {
        loggedIn = username == this->username && password == this->password;
        return loggedIn;
    }

    void logout()
    {
        loggedIn = false;
    }

    void addCourse(string userId, Course *course)
    {
        Course **newRegisteredCourses = new Course *[numCourses + 1];

        // Copy old data
        for (int i = 0; i < numCourses; i++)
        {
            registeredCourses[i] = newRegisteredCourses[i];
        }

        // Add new data
        newRegisteredCourses[numCourses] = course;

        // replace old list with new
        delete[] registeredCourses;
        registeredCourses = newRegisteredCourses;

        numCourses++;
    }
};

class Advisor : public User
{
public:
    Advisor(
        string username,
        string password)
        : User(username, password) {}

    bool login(string username, string studentId, string password)
    {
        loggedIn = username == this->username && password == this->password;
        return loggedIn;
    }

    void logout()
    {
        loggedIn = false;
    }

    bool approveCourse(string studentId, Course &course)
    {
        // pre requisites can be checked here according to the studentId
        return true;
    }
};

class Registrar
{

public:
    void generateBillReport(Student &student)
    {
        float total = 0;

        for (int i = 0; i < student.numCourses; i++)
        {
            cout << "Course Code: " << student.registeredCourses[i]->getCode() << endl;
            cout << "Per Credit: " << student.registeredCourses[i]->getCostPerCredit() << endl;
            cout << "Credit Hours: " << student.registeredCourses[i]->getCreditHours() << endl;
            cout << "Course Cost: " << student.registeredCourses[i]->getCreditHours() * student.registeredCourses[i]->getCostPerCredit() << endl
                 << endl;

            total += student.registeredCourses[i]->getCreditHours() * student.registeredCourses[i]->getCostPerCredit();
        }

        cout << "TOTAL: " << total << endl;
    }
};

class Faculty : public User
{
public:
    Faculty(
        string username,
        string password)
        : User(username, password) {}

    void printStudentTranscript(Student &student)
    {
        for (int i = 0; i < student.numCourses; i++)
        {
            cout << "Code: " << student.registeredCourses[i]->getCode() << endl;
            cout << "Description: " << student.registeredCourses[i]->getDescription() << endl;
            cout << "Section: " << student.registeredCourses[i]->getSection() << endl
                 << endl;
        }
    }

    bool checkEnrollment(string studentId, Student classList[])
    {
        for (int i = 0; i < 5; i++)
        {
            if (studentId == classList[i].studentId)
            {
                return true;
            }
        }
    }

    string getPhoneNumber(Student &student)
    {
        return student.phoneNumber;
    }

    bool login(string username, string password)
    {
        loggedIn = username == this->username && password == this->password;
        return loggedIn;
    }

    void logout()
    {
        loggedIn = false;
    }
};

int main()
{
    Student classList[5] = {
        Student("username1", "1234567890", "0801", "03001`234567"),
        Student("username2", "1234567890", "0802", "03001`232352"),
        Student("username3", "1234567890", "0803", "03001`234234"),
        Student("username4", "1234567890", "0804", "03001`234567"),
        Student("username5", "1234567890", "0805", "03001`234535"),
    };

    Faculty faculty("username6", "1234567890");

    faculty.checkEnrollment("0802", classList);
}