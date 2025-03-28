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
    Ticket(int id, string name, double cost, string d, string dest)
        : ticketID(id), passengerName(name), price(cost), date(d), destination(dest) {}

    virtual void reserve() { cout << "Ticket reserved for " << passengerName << "\n"; }
    virtual void cancel() { cout << "Ticket cancelled for " << passengerName << "\n"; }
    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName
             << "\nPrice: Rs." << price << "\nDate: " << date
             << "\nDestination: " << destination << "\n";
    }
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double cost, string d, string dest, string airline, string flightNo, string sClass)
        : Ticket(id, name, cost, d, dest), airlineName(airline), flightNumber(flightNo), seatClass(sClass) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight No: " << flightNumber << "\nSeat Class: " << seatClass << "\n";
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double cost, string d, string dest, string trainNo, string coach, string depTime)
        : Ticket(id, name, cost, d, dest), trainNumber(trainNo), coachType(coach), departureTime(depTime) {}

    void reserve() override {
        cout << "Train ticket reserved. Seat auto-assigned for " << passengerName << "\n";
    }
   
};

class BusTicket : public Ticket {
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double cost, string d, string dest, string company, int seatNo)
        : Ticket(id, name, cost, d, dest), busCompany(company), seatNumber(seatNo) {}

    void cancel() override {
        cout << "Bus ticket cancelled for " << passengerName << ". Last-minute refund granted.\n";
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double cost, string d, string dest, string artist, string ven, string sType)
        : Ticket(id, name, cost, d, dest), artistName(artist), venue(ven), seatType(sType) {}

    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << "\n";
    }
};

int main() {
    FlightTicket flight(101, "Ali", 25000.0, "2025-05-10", "Karachi", "PIA", "PK301", "Economy");
    TrainTicket train(102, "Ahmed", 1500.0, "2025-06-15", "Lahore", "GreenLine", "AC", "08:00 AM");
    BusTicket bus(103, "Sara", 800.0, "2025-07-20", "Islamabad", "Daewoo", 12);
    ConcertTicket concert(104, "Fatima", 5000.0, "2025-08-25", "Karachi", "Atif Aslam", "Expo Center", "VIP");

    flight.displayTicketInfo();
    flight.reserve();
    cout << "------------------------\n";

    train.displayTicketInfo();
    train.reserve();
    cout << "------------------------\n";

    bus.displayTicketInfo();
    bus.cancel();
    cout << "------------------------\n";

    concert.displayTicketInfo();
    concert.reserve();
    cout << "------------------------\n";

    return 0;
}
