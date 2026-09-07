#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP
#include "Seat.cpp"
using namespace std;

class ShowSeat {
private:
    Seat* seat;
    bool isBooked;

public:
    ShowSeat(Seat* s) : seat(s), isBooked(false) {}

    Seat* getSeat() const { return seat; }
    bool isAvailable() const { return !isBooked; }

    void book() { isBooked = true; }
    void release() { isBooked = false; }
};
#endif
