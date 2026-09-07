
#ifndef SEAT_CPP
#define SEAT_CPP
#include <string>
using namespace std;

const double SILVER_PRICE = 150.0;
const double GOLD_PRICE = 250.0;
const double PLATINUM_PRICE = 400.0;

class Seat {
private:
    string seatNumber;
    string type;

public:
    Seat(string number, string t) : seatNumber(number), type(t) {}

    string getSeatNumber() const { return seatNumber; }
    string getType() const { return type; }

    double getPrice() const {
        if (type == "SILVER") return SILVER_PRICE;
        if (type == "GOLD") return GOLD_PRICE;
        return PLATINUM_PRICE;
    }
};
#endif
