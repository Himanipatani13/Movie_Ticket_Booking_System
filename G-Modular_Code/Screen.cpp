#ifndef SCREEN_CPP
#define SCREEN_CPP
#include <vector>
#include "Seat.cpp"
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int number) : screenNumber(number) {}

    void addSeat(const Seat& seat) { seats.push_back(seat); }
    int getScreenNumber() const { return screenNumber; }
    vector<Seat>& getSeats() { return seats; }
};
#endif
