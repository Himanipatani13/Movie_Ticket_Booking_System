#ifndef BOOKING_CPP
#define BOOKING_CPP
#include <vector>
#include <string>
#include "Show.cpp"
#include "ShowSeat.cpp"
#include "Customer.cpp"
using namespace std;

class Booking {
private:
    string bookingId;
    Show* show;
    Customer* customer;
    vector<ShowSeat*> seats;
    double totalAmount;
    string status;

public:
    Booking(string id, Show* s, Customer* c, vector<ShowSeat*> bookedSeats, double amt) {
        this->bookingId = id;
        this->show = s;
        this->customer = c;
        this->seats = bookedSeats;
        this->totalAmount = amt;
        this->status = "PENDING";
    }

    string getBookingId() const { return bookingId; }
    Show* getShow() const { return show; }
    Customer* getCustomer() const { return customer; }
    vector<ShowSeat*>& getSeats() { return seats; }
    double getTotalAmount() const { return totalAmount; }
    string getStatus() const { return status; }

    void confirm() { status = "CONFIRMED"; }
    void fail() { status = "FAILED"; }
    void cancel() { status = "CANCELLED"; }
};
#endif
