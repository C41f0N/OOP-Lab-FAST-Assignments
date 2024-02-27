#include <iostream>

using namespace std;

class Appointment
{
    string appointmentDetails;
    float cost;
    static int numTotalAppointments;
    static float totalEarnings;

public:
    Appointment(string appointmentDetails, float cost)
    {
        this->appointmentDetails = appointmentDetails;
        this->cost = cost;

        numTotalAppointments++;
        totalEarnings += cost;
    }

    string getAppointmentDetails()
    {
        return this->appointmentDetails;
    }

    void setAppointmentDetails(string appointmentDetails)
    {
        this->appointmentDetails = appointmentDetails;
    }

    float getCost()
    {
        return this->cost;
    }

    void setCost(float cost)
    {
        this->cost = cost;
    }

    static float calculateAverageCost()
    {
        return (float)totalEarnings / numTotalAppointments;
    }
};

int Appointment::numTotalAppointments = 0;
float Appointment::totalEarnings = 0.0;

int main()
{
    // Some appointments...
    Appointment appointment1("Just a trim", 100.0);
    Appointment appointment2("Color the hair black", 500.0);
    Appointment appointment3("Color the hair brown", 500.0);
    Appointment appointment4("Babar Azam Cut", 10000.0);

    cout << "The average cost for all the appointments: " << Appointment::calculateAverageCost() << endl;
}