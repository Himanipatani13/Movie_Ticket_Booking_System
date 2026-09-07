#include <iostream>
#include <vector>
#include <string>
#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "Show.cpp"
#include "ShowSeat.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"
using namespace std;

void setupCinema(Cinema& cinema, vector<Show>& shows) {
    cinema.addMovie(Movie("M1", "3 Idiots", "Hindi", 170));
    cinema.addMovie(Movie("M2", "Interstellar", "English", 169));

    Screen screen1(1);
    for (string num : {"A1", "A2", "A3", "A4"}) screen1.addSeat(Seat(num, "SILVER"));
    for (string num : {"B1", "B2", "B3"}) screen1.addSeat(Seat(num, "GOLD"));
    for (string num : {"C1", "C2"}) screen1.addSeat(Seat(num, "PLATINUM"));

    Screen screen2(2);
    for (string num : {"A1", "A2", "A3", "A4"}) screen2.addSeat(Seat(num, "SILVER"));
    for (string num : {"B1", "B2", "B3"}) screen2.addSeat(Seat(num, "GOLD"));
    for (string num : {"C1", "C2"}) screen2.addSeat(Seat(num, "PLATINUM"));

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    shows.push_back(Show("S1", &cinema.getMovies()[0], &cinema.getScreens()[0], "06:00 PM"));
    shows.push_back(Show("S2", &cinema.getMovies()[0], &cinema.getScreens()[1], "09:00 PM"));
    shows.push_back(Show("S3", &cinema.getMovies()[1], &cinema.getScreens()[0], "09:00 PM"));
}

int getValidChoice(int minVal, int maxVal) {
    int choice;
    while (!(cin >> choice) || choice < minVal || choice > maxVal) {
        if (cin.eof()) {
            cout << "\n  No more input. Exiting.\n";
            exit(0);
        }
        cout << "  Invalid choice. Enter a number between " << minVal
             << " and " << maxVal << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return choice;
}

int main() {
    Cinema cinema("PVR Dehradun");
    vector<Show> shows;
    setupCinema(cinema, shows);

    BookingService bookingService;
    Customer customer("Guest", "9999999999");

    cout << "===== MOVIE TICKET BOOKING =====\n";
    bool running = true;
    while (running) {
        cout << "\n1. Movies  2. Book  3. Cancel  4. My tickets   0. Exit\nChoose: ";
        int choice = getValidChoice(0, 4);

        if (choice == 0) {
            running = false;

        } else if (choice == 1) {
            cinema.listMovies();

        } else if (choice == 2) {
            cinema.listMovies();
            cout << "Choose movie: ";
            int movieChoice = getValidChoice(1, (int)cinema.getMovies().size());
            Movie* selectedMovie = &cinema.getMovies()[movieChoice - 1];

            vector<Show*> matchingShows;
            for (Show& s : shows) {
                if (s.getMovie() == selectedMovie) matchingShows.push_back(&s);
            }
            if (matchingShows.empty()) {
                cout << "  No shows available for this movie.\n";
                continue;
            }
            for (size_t i = 0; i < matchingShows.size(); i++) {
                cout << "  [" << (i + 1) << "] Screen-" << matchingShows[i]->getScreen()->getScreenNumber()
                     << "\t" << matchingShows[i]->getStartTime() << "\n";
            }
            cout << "Choose show: ";
            int showChoice = getValidChoice(1, (int)matchingShows.size());
            Show* selectedShow = matchingShows[showChoice - 1];

            selectedShow->printSeatLayout();

            cin.ignore();
            cout << "Seats (e.g. A1,B2): ";
            string seatInput;
            getline(cin, seatInput);
            vector<string> seatNumbers = BookingService::splitSeatNumbers(seatInput);

            Booking* booking = bookingService.bookSeats(selectedShow, &customer, seatNumbers);
            if (booking == nullptr) continue;

            cout << "Pay by: 1.UPI  2.Card  3.Cash > ";
            int payChoice = getValidChoice(1, 3);
            Payment* payment;
            if (payChoice == 1) payment = new UpiPayment(booking->getTotalAmount());
            else if (payChoice == 2) payment = new CardPayment(booking->getTotalAmount());
            else payment = new CashPayment(booking->getTotalAmount());

            bookingService.processPayment(booking, payment);
            delete payment;

        } else if (choice == 3) {
            cin.ignore();
            cout << "Enter booking id to cancel: ";
            string id;
            getline(cin, id);
            bookingService.cancelBooking(id);

        } else if (choice == 4) {
            if (bookingService.getAllBookings().empty()) {
                cout << "  No tickets yet.\n";
            }
            for (Booking* b : bookingService.getAllBookings()) {
                cout << "  " << b->getBookingId() << "  "
                     << b->getStatus()
                     << "  Rs." << b->getTotalAmount() << "\n";
            }
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
