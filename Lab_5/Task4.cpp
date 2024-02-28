#include <iostream>

using namespace std;

class Course
{
    string code;
    string name;
    int credHours;

public:
    Course() {}

    Course(string code, string name, int credHours)
    {
        this->code = code;
        this->name = name;
        this->credHours = credHours;
    }

    string getCode()
    {
        return code;
    }

    string getName()
    {
        return name;
    }

    int getCredHours()
    {
        return credHours;
    }
};

class Student
{
    string id;
    string name;
    Course *courses;
    int numOfCourses;

public:
    Student(string id, string name)
    {
        this->id = id;
        this->name = name;
        numOfCourses = 0;
    }

    void enroll(Course &course)
    {
        numOfCourses++;
        Course *newCourseList = new Course[numOfCourses];

        // copy old records to new list
        for (int i = 0; i < numOfCourses - 1; i++)
        {
            newCourseList[i] = this->courses[i];
        }
        newCourseList[numOfCourses - 1] = course;

        // Delete old pointer

        if (numOfCourses - 1 > 0)
        {
            delete[] courses;
        }

        // Replace variable with new pointer
        courses = newCourseList;
    }

    void drop(Course &course)
    {
        Course *newCourseList = new Course[numOfCourses - 1];

        int i = 0;

        // Copy as it is until record is found
        while (i < numOfCourses && (this->courses[i].getCode() != course.getCode()))
        {
            newCourseList[i] = this->courses[i];
            i++;
        }

        // Once record is found, skip it and copy the rest
        while (i < numOfCourses - 1)
        {
            newCourseList[i] = this->courses[i + 1];
            i++;
        }

        numOfCourses--;

        // Delete old pointer
        delete[] courses;

        // Replace variable with new pointer
        courses = newCourseList;
    }

    int getTotalCreditHours()
    {
        int totalHours = 0;

        for (int i = 0; i < numOfCourses; i++)
        {
            totalHours += courses[i].getCredHours();
        }

        return totalHours;
    }

    void printEnrolledCourses()
    {
        cout << "===================================" << endl;
        cout << "     PRINTING ENROLLED COURSES" << endl;
        cout << "===================================" << endl;
        for (int i = 0; i < numOfCourses; i++)
        {
            cout << "Course Name: " << courses[i].getName() << endl;
            cout << "Credit Hours: " << courses[i].getCredHours() << endl;
            cout << "Course Code: " << courses[i].getCode() << endl
                 << endl;
        }
    }
};

int main()
{
    Course course1("001", "Biology", 3);
    Course course2("002", "Physics", 2);
    Course course3("003", "Math", 3);

    Student student1("23K0703", "Sarim Ahmed");

    student1.enroll(course1);
    student1.printEnrolledCourses();

    student1.enroll(course2);
    student1.enroll(course3);
    student1.printEnrolledCourses();

    student1.drop(course2);
    student1.printEnrolledCourses();
}