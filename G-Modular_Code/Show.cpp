#ifndef SHOW_CPP
#define SHOW_CPP
#include <vector>
#include <string>
#include <iostream>
#include "Movie.cpp"
#include "Screen.cpp"
#include "ShowSeat.cpp"
using namespace std;

class Show {
private:
    string showId;
    Movie* movie;
    Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(string id, Movie* m, Screen* s, string time)
        : showId(id), movie(m), screen(s), startTime(time) {
        for (Seat& seat : s->getSeats()) {
            showSeats.push_back(ShowSeat(&seat));
        }
    }

    string getShowId() const { return showId; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }
    vector<ShowSeat>& getShowSeats() { return showSeats; }

    ShowSeat* findShowSeat(const string& seatNumber) {
        for (ShowSeat& ss : showSeats) {
            if (ss.getSeat()->getSeatNumber() == seatNumber) return &ss;
        }
        return nullptr;
    }

    void printSeatLayout() const {
        cout << "\n  SCREEN-" << screen->getScreenNumber() << "  " << startTime
             << "  |  " << movie->getTitle() << "\n";
        printRow("SILVER");
        printRow("GOLD");
        printRow("PLATINUM");
        cout << "  ( [ ] = available   [X] = booked )\n";
    }

private:
    void printRow(const string& type) const {
        cout << "  " << type << "\t";
        for (const ShowSeat& ss : showSeats) {
            if (ss.getSeat()->getType() == type) {
                cout << ss.getSeat()->getSeatNumber()
                     << (ss.isAvailable() ? "[ ] " : "[X] ");
            }
        }
        cout << "\n";
    }
};
#endif
