#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP
#include <vector>
#include "ShowSeat.cpp"
using namespace std;

class PriceCalculator {
public:
    static double calculateTotal(vector<ShowSeat*>& seats) {
        double total = 0.0;
        for (ShowSeat* s : seats) {
            total += s->getSeat()->getPrice();
        }
        return total;
    }
};
#endif
