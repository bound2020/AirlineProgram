#include "Airline.h"

using namespace std;

void Airline::addFlight()
{
    string flightName;
    int seatNumber = 0;
    cout << "Enter flight name: ";
    cin >> flightName;
    cout << "Enter flight seat number: ";
    cin >> seatNumber;
    mFlights.push_back(Flight(flightName, seatNumber));
}

void Airline::deleteFlight(string inFlightName)
{
    for (list<Flight>::iterator it = mFlights.begin(); it != mFlights.end(); it++) {
        if ((*it).getName() == inFlightName) {
            mFlights.erase(it);
            cout << inFlightName << "deleted!" << endl;
            return;
        }
    }
    cout << "No related flight" << endl;
}

void Airline::displayAll()
{
    for (list<Flight>::iterator it = mFlights.begin(); it != mFlights.end(); it++) {
        cout << "flight name: " << (*it).getName() << " seat number: " << (*it).getCapacity() << endl;
    }
}

Flight* Airline::searchFlight(string inFlightName)
{
    for (list<Flight>::iterator it = mFlights.begin(); it != mFlights.end(); it++) {
        if ((*it).getName() == inFlightName) {
            return &(*it);
        }
    }
    return NULL;
}

bool Flight::isFull()
{
    return getRemaining() == 0;
}

int Flight::pickSeat()
{
    int s = mSeats.back();
    mSeats.pop_back();
    return s;
}

void Flight::book()
{
    if (isFull()) {
        cout << "Sorry, all the seats are booked." << endl;
        return;
    }

    string pn;
    cout << "Please enter your name: ";
    cin >> pn;
    int s = pickSeat();
    Passenger ps = Passenger(pn, s);
    mPassengers.push_back(ps);
    cout << "Booked. Name: " << ps.getName() << " Seat Number: " << s << endl;
}

void Flight::cancel()
{
    if (mPassengers.size() == 0) {
        cout << "No passenger yet" << endl;
        return;
    }
    string pn;
    cout << "Please enter your name: ";
    cin >> pn;
    for (list<Passenger>::iterator it = mPassengers.begin(); it != mPassengers.end(); it++) {
        if ((*it).getName() == pn) {
            mPassengers.erase(it);
            cout << "Canceled. Name: " << pn << endl;
            mSeats.push_back((*it).getSeat());
            return;
        }
    }
    cout << "Not found." << endl;
}

void Flight::display()
{
    cout << "Flight: " << getName() << " Remains: " << getRemaining() << endl;
}




