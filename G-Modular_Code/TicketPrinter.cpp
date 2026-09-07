#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP
#include <iostream>
#include "Booking.cpp"
using namespace std;

class TicketPrinter {
public:
    static void printTicket(Booking& booking) {
        cout << "\n  ================ TICKET ================\n";
        cout << "  Booking ID : " << booking.getBookingId() << "\n";
        cout << "  Movie      : " << booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "  Screen     : Screen-" << booking.getShow()->getScreen()->getScreenNumber()
             << "  " << booking.getShow()->getStartTime() << "\n";
        cout << "  Seats      : ";
        for (size_t i = 0; i < booking.getSeats().size(); i++) {
            cout << booking.getSeats()[i]->getSeat()->getSeatNumber();
            if (i != booking.getSeats().size() - 1) cout << ", ";
        }
        cout << "\n  Amount     : Rs." << booking.getTotalAmount()
             << "\tStatus: CONFIRMED\n";
        cout << "  =========================================\n";
    }
};
#endif
