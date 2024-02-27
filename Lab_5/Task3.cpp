#include <iostream>

using namespace std;

inline float calculateBattingAverage()
{
    int numOfRuns, numOut;
    float battingAverage;

    cout << "Enter the total number of runs made: ";
    cin >> numOfRuns;

    cout << "Enter the total number of times the player was dismissed: ";
    cin >> numOut;

    battingAverage = (float)numOfRuns / numOut;

    return battingAverage;
}

inline float calculateStrikeRate()
{
    float strikeRate;
    int numOfRuns, numOfBalls;

    cout << "Enter the total number of runs made: ";
    cin >> numOfRuns;

    cout << "Enter the total number of balls faced: ";
    cin >> numOfBalls;

    strikeRate = (float)((numOfRuns / numOfBalls) * 100);

    return strikeRate;
}

int main()
{
    float strikeRate = calculateStrikeRate(), battingAverage = calculateBattingAverage();

    cout << "Strike Rate: " << strikeRate << endl;
    cout << "Batting Average: " << battingAverage << endl;
}