#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "Show.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
using namespace std;

class BookingService {
private:
    vector<Booking*> bookings;
    static int nextBookingId;

public:
    ~BookingService() {
        for (Booking* b : bookings) delete b;
    }

    static vector<string> splitSeatNumbers(const string& input) {
        vector<string> result;
        stringstream ss(input);
        string token;
        while (getline(ss, token, ',')) {
            size_t start = token.find_first_not_of(" \t");
            size_t end = token.find_last_not_of(" \t");
            if (start != string::npos) result.push_back(token.substr(start, end - start + 1));
        }
        return result;
    }

    Booking* bookSeats(Show* show, Customer* customer, const vector<string>& seatNumbers) {
        vector<ShowSeat*> targetSeats;
        for (const string& num : seatNumbers) {
            ShowSeat* ss = show->findShowSeat(num);
            if (ss == nullptr) {
                cout << "  Error: seat " << num << " does not exist on this screen.\n";
                return nullptr;
            }
            if (!ss->isAvailable()) {
                cout << "  Error: seat " << num << " is already BOOKED.\n";
                return nullptr;
            }
            targetSeats.push_back(ss);
        }
        if (targetSeats.empty()) {
            cout << "  Error: no valid seats selected.\n";
            return nullptr;
        }

        double total = PriceCalculator::calculateTotal(targetSeats);
        string id = "BK" + to_string(1000 + nextBookingId);
        nextBookingId++;
        Booking* booking = new Booking(id, show, customer, targetSeats, total);

        cout << "\n";
        for (ShowSeat* s : targetSeats) {
            cout << "  " << s->getSeat()->getSeatNumber() << " "
                 << s->getSeat()->getType()
                 << "\tRs." << s->getSeat()->getPrice() << "\n";
        }
        cout << "  TOTAL\t\tRs." << total << "\n";

        bookings.push_back(booking);
        return booking;
    }

    bool processPayment(Booking* booking, Payment* payment) {
        bool success = payment->pay(booking->getTotalAmount());
        if (success) {
            for (ShowSeat* s : booking->getSeats()) s->book();
            booking->confirm();
            TicketPrinter::printTicket(*booking);
        } else {
            booking->fail();
            cout << "  Payment failed. Booking " << booking->getBookingId()
                 << " NOT confirmed. Seats remain available.\n";
        }
        return success;
    }

    bool cancelBooking(const string& bookingId) {
        for (Booking* b : bookings) {
            if (b->getBookingId() == bookingId) {
                if (b->getStatus() != "CONFIRMED") {
                    cout << "  Error: booking " << bookingId
                         << " is not an active confirmed booking.\n";
                    return false;
                }
                for (ShowSeat* s : b->getSeats()) s->release();
                b->cancel();
                cout << "  Booking " << bookingId << " cancelled. Seats released.\n";
                return true;
            }
        }
        cout << "  Error: booking id " << bookingId << " not found.\n";
        return false;
    }

    vector<Booking*>& getAllBookings() { return bookings; }
};

int BookingService::nextBookingId = 1;
#endif
