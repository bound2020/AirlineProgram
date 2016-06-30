#ifndef AIRLINE_H_INCLUDED
#define AIRLINE_H_INCLUDED
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

class Flight;    //forward declaration
class Passenger;

class Airline
{
public:
    Airline()
    {
        cout << "Welcome to the Airline ticket booking system." << endl;
    }
    void addFlight();
    void deleteFlight(string);
    void displayAll();
    Flight* searchFlight(string);
private:
    list<Flight> mFlights;
};

class Flight
{
public:
    Flight() {}
    Flight(int inNum): mFlightName(""), mCapacity(inNum) {}
    Flight(string inFlightName, int inCapacity)
    {
        mFlightName = inFlightName;
        mCapacity = inCapacity;
        for (int i = mCapacity - 1; i > 0; --i)
            mSeats.push_back(i);
    }
    void display();
    void book();
    bool isFull();
    void cancel();
    string getName() {return mFlightName;}
    int getCapacity() {return mCapacity;}
    void setName(string inFlightName) {mFlightName = inFlightName;}
    void setCapacity(int inCapacity) {mCapacity = inCapacity;}
    int getRemaining() {return mCapacity - mPassengers.size();}
    int pickSeat();
private:
    list<Passenger> mPassengers;
    string mFlightName;
    int mCapacity;
    vector<int> mSeats;
};

class Passenger
{
public:
    Passenger(){}
    Passenger(string inPsName, int inSeatNo): mPassengerName(inPsName), mSeatNumber(inSeatNo) {}
    string getName() {return mPassengerName;}
    void setName(string);
    int getSeat() {return mSeatNumber;}
    void setSeat();
private:
    string mPassengerName;
    int mSeatNumber;
};

#endif // AIRLINE_H_INCLUDED
