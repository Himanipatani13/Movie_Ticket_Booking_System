#ifndef CINEMA_CPP
#define CINEMA_CPP
#include <vector>
#include <string>
#include <iostream>
#include "Movie.cpp"
#include "Screen.cpp"
using namespace std;

class Cinema {
private:
    string name;
    vector<Movie> movies;
    vector<Screen> screens;

public:
    Cinema(string n) : name(n) {}

    void addMovie(const Movie& m) { movies.push_back(m); }
    void addScreen(const Screen& s) { screens.push_back(s); }

    vector<Movie>& getMovies() { return movies; }
    vector<Screen>& getScreens() { return screens; }

    void listMovies() const {
        cout << "\n  [Movies currently playing]\n";
        for (size_t i = 0; i < movies.size(); i++) {
            cout << "  [" << (i + 1) << "] " << movies[i].getTitle()
                 << "\t" << movies[i].getLanguage()
                 << "\t" << movies[i].getDurationMinutes() << " min\n";
        }
    }
};
#endif
