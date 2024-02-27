#include <iostream>

using namespace std;

class Report
{

private:
    string adno, name;
    float marks[5], average;

    void getAvg()
    {
        average = (float)(marks[0] + marks[1] + marks[2] + marks[3] + marks[4]) / 5;
    }

public:
    void readInfo(string adnoP, string nameP, float marksP[5])
    {
        // validate addno
        if (adnoP.length() == 4 && ((adnoP[0] - '0') > 9 || (adnoP[0] - '0') < 0))
        {
            adno = adnoP;
            name = nameP;

            for (int i = 0; i < 5; i++)
            {
                marks[i] = marksP[i];
            }

            getAvg();
        }
    }

    void displayInfo()
    {
        cout << "Student Name: " << name << endl;
        cout << "Student Avg: " << average << endl;
        cout << "Subject 1 Marks: " << marks[0] << endl;
        cout << "Subject 2 Marks: " << marks[1] << endl;
        cout << "Subject 3 Marks: " << marks[2] << endl;
        cout << "Subject 4 Marks: " << marks[3] << endl;
        cout << "Subject 5 Marks: " << marks[4] << endl
             << endl;
    }
};

int main()
{
    Report myReport;
    float marks[5] = {1.2, 2.7, 3.1, 4.2, 5.1};

    myReport.readInfo("A123", "Sarim", marks);

    myReport.displayInfo();
}