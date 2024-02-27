#include <iostream>

using namespace std;

class Batsman
{
    int bcode, innings, notout, runs;
    string bname;
    float batavg;

    void calcavg()
    {
        batavg = (float)runs / (innings - notout);
    }

public:
    void readData(int codeP, string nameP, int inningsP, int notoutP, int runsP)
    {
        bcode = codeP;
        bname = nameP;
        innings = inningsP;
        notout = notoutP;
        runs = runsP;

        calcavg();
    }

    void displayData()
    {
        cout << "Code: " << bcode << endl;
        cout << "Name: " << bname << endl;
        cout << "Innings: " << innings << endl;
        cout << "Not Out: " << notout << endl;
        cout << "Bat Avg: " << batavg << endl;
    }
};

int main()
{
    Batsman batsman;

    batsman.readData(1234, "Shaheen", 20, 18, 500);
    batsman.displayData();
    return 0;
}