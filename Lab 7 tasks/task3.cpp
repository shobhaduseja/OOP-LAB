#include <iostream>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest) 
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << endl;
    }

    virtual void cancel() {
        cout << "Ticket canceled for " << passengerName << endl;
    }

    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger: " << passengerName << endl;
        cout << "Price: $" << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
};

class FlightTicket : public Ticket {
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, string flight, string seat) 
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, string train, string coach, string time) 
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}

    void reserve() override {
        cout << "Ticket reserved with auto-assigned seat for " << passengerName << endl;
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class BusTicket : public Ticket {
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string company, string seat) 
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout <<  "ticket canceled refund for " << passengerName << endl;
    }

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string seat) 
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight(1, "shobha", 22.22, "2022-01-22", "karachi", "sukker","ddd", "Economy");
    TrainTicket train(2, "aseelah", 22.22, "2022-01-20", "lahore", "ssd123", "Sleeper", "12:00 AM");
    BusTicket bus(3, "sam", 222, "2022-01-2", "islamabad", "yale", "xysw9");
    ConcertTicket concert(4, "abeer", 333.33, "2022-01-01", "fast uni", "hasan raheem", "ground", "VIP");

    flight.displayTicketInfo();
    train.reserve();
    train.displayTicketInfo();
    bus.cancel();
    bus.displayTicketInfo();
    concert.displayTicketInfo();

    return 0;
}