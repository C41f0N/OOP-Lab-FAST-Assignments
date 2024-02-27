#include <iostream>

using namespace std;

class Calendar
{
    int year;
    string tasksDetailsArray[12][31];

public:
    Calendar(int yearP)
    {
        year = yearP;
    }

    void addTask(string taskDetailsP, int date, int month)
    {
        tasksDetailsArray[month][date] = taskDetailsP;
    }

    void removeTask(int date, int month)
    {
        tasksDetailsArray[month][date] = "";
    }

    void printTasks()
    {
        for (int month = 0; month < 12; month++)
        {
            for (int day = 0; day < 31; day++)
            {
                if (tasksDetailsArray[month][day].length() > 0)
                {
                    cout << "Day: " << day << "\nMonth: " << month << "\nTaskName: " << tasksDetailsArray[month][day] << endl
                         << endl;
                }
            }
        }
    }
};

int main()
{
    Calendar myCalendar(2024);

    // Adding tasks
    myCalendar.addTask("Wash Car", 24, 11);
    myCalendar.addTask("Make Bed", 25, 1);
    myCalendar.addTask("Kill", 24, 5);
    myCalendar.addTask("Hide Body", 21, 6);
    myCalendar.addTask("Frame my son", 27, 9);
    myCalendar.addTask("Happy Birthday", 7, 11);

    cout << "=================AFTER ADDING=================" << endl;
    myCalendar.printTasks();

    // Removing Tasks
    myCalendar.removeTask(24, 05);
    myCalendar.removeTask(21, 06);
    myCalendar.removeTask(27, 9);

    cout << "=====================AFTER REMOVING=================" << endl;
    myCalendar.printTasks();

    return 0;
}