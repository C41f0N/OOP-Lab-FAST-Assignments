#include <iostream>

using namespace std;

class Flight
{
    string **schedule;
    int numOfFlights;

public:
    Flight(int numOfFlights, string **schedule)
    {
        this->numOfFlights = numOfFlights;

        if (this->numOfFlights > 0)
        {
            // Allocate Memory
            this->schedule = new string *[this->numOfFlights];

            for (int i = 0; i < this->numOfFlights; i++)
            {
                this->schedule[i] = new string[5];
            }

            // Copying Data
            for (int i = 0; i < this->numOfFlights; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    this->schedule[i][j] = schedule[i][j];
                }
            }
        }
    }

    int getNumOfFlights()
    {
        return numOfFlights;
    }

    string **getSchedule()
    {
        return schedule;
    }
};

class Reservation
{
    string clientName, passportNumber, date, departurePoint, destinationPoint, seatType;

public:
    Reservation(
        string clientName,
        string passportNumber,
        string date,
        string departurePoint,
        string destinationPoint,
        string seatType)
        : clientName(clientName),
          passportNumber(passportNumber),
          date(date),
          departurePoint(departurePoint),
          destinationPoint(destinationPoint),
          seatType(seatType) {}

    void display()
    {
        cout << endl
             << "Passenger Name: " << clientName << endl;
        cout << "Passport Number: " << passportNumber << endl;
    }

    bool checkAvailability(Flight &flight)
    {

        bool booked = false;
        string **schedule = flight.getSchedule();

        for (int i = 0; i < flight.getNumOfFlights(); i++)
        {

            // Check if date and locations match
            if (schedule[i][0] == date && schedule[i][1] == departurePoint && schedule[i][2] == destinationPoint)
            {
                // See if seats are available
                if (seatType == "economy" && (stoi(schedule[i][3]) > 0))
                {
                    schedule[i][3] = to_string(stoi(schedule[i][3]) - 1);
                    booked = true;
                    cout << "Reservation made on " << schedule[i][0] << " from " << departurePoint << " to " << destinationPoint << ", " << seatType << " class seats." << endl;
                    break;
                }
                else if (seatType == "business" && (stoi(schedule[i][4]) > 0))
                {
                    schedule[i][4] = to_string(stoi(schedule[i][4]) - 1);
                    booked = true;
                    cout << "Reservation made on " << schedule[i][0] << " from " << departurePoint << " to " << destinationPoint << ", " << seatType << " class seats." << endl;
                    break;
                }
            }
        }

        if (booked)
        {
            return true;
        }
        else
        {
            char choice;

            // Ask if the user would want to book a tentative flight
            cout << "Would you opt for a tentaive flight? (Y/n): ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y')
            {

                booked = tentativeBooking(flight);
            }

            if (!booked)
            {
                cout << "No reservations could be made." << endl;
            }

            return booked;
        }
    }

    bool tentativeBooking(Flight &flight)
    {
        int choice;
        bool booked;
        string **schedule = flight.getSchedule();

        // Ask if they want it on the same date
        cout
            << "Do you want the tentative flight to be on the same day? (Y/n): ";
        cin >> choice;

        // Check on location only
        if (choice == 'Y' || choice == 'y')
        {
            for (int i = 0; i < flight.getNumOfFlights(); i++)
            {

                if (schedule[i][0] == date)
                {
                    // See if seats are available
                    if (seatType == "economy" && (stoi(schedule[i][3]) > 0))
                    {
                        schedule[i][3] = to_string(stoi(schedule[i][3]) - 1);
                        booked = true;
                        cout << "Reservation made on " << schedule[i][0] << " from " << schedule[i][1] << " to " << schedule[i][2] << ", " << seatType << " class seats." << endl;
                        break;
                    }
                    else if (seatType == "business" && (stoi(schedule[i][4]) > 0))
                    {
                        schedule[i][4] = to_string(stoi(schedule[i][4]) - 1);
                        booked = true;
                        cout << "Reservation made on " << schedule[i][0] << " from " << schedule[i][2] << " to " << schedule[i][2] << ", " << seatType << " class seats." << endl;
                        break;
                    }
                }
            }
        }
        // Check any available flight
        else
        {
            for (int i = 0; i < flight.getNumOfFlights(); i++)
            {

                // See if seats are available
                if (seatType == "economy" && (stoi(schedule[i][3]) > 0))
                {
                    schedule[i][3] = to_string(stoi(schedule[i][3]) - 1);
                    booked = true;
                    cout << "Reservation made on " << schedule[i][0] << " from " << schedule[i][1] << " to " << schedule[i][2] << ", " << seatType << " class seats." << endl;
                    break;
                }
                else if (seatType == "business" && (stoi(schedule[i][4]) > 0))
                {
                    schedule[i][4] = to_string(stoi(schedule[i][4]) - 1);
                    booked = true;
                    cout << "Reservation made on " << schedule[i][0] << " from " << schedule[i][1] << " to " << schedule[i][2] << ", " << seatType << " class seats." << endl;
                    break;
                }
            }
        }

        return booked;
    }
};

int main()
{
    string **schedule;

    // Allocate Memory
    schedule = new string *[3];

    for (int i = 0; i < 5; i++)
    {
        schedule[i] = new string[5];
    }

    // reservation 1
    schedule[0][0] = "12-12-23";
    schedule[0][1] = "London";
    schedule[0][2] = "Karachi";
    schedule[0][3] = "10";
    schedule[0][4] = "5";

    // reservation 2
    schedule[1][0] = "12-11-23";
    schedule[1][1] = "London";
    schedule[1][2] = "Karachi";
    schedule[1][3] = "20";
    schedule[1][4] = "5";

    // reservation 3
    schedule[2][0] = "12-10-23";
    schedule[2][1] = "London";
    schedule[2][2] = "Karachi";
    schedule[2][3] = "10";
    schedule[2][4] = "19";

    Flight flight(3, schedule);

    Reservation reservation("Sarim", "1234567890", "12-12-23", "London", "Karachi", "economy");

    reservation.checkAvailability(flight);

    reservation.display();
}