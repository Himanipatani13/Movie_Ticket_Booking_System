#ifndef MOVIE_CPP
#define MOVIE_CPP
#include <string>
using namespace std;

class Movie {
private:
    string movieId;
    string title;
    string language;
    int durationMinutes;

public:
    Movie(string id, string t, string lang, int duration)
        : movieId(id), title(t), language(lang), durationMinutes(duration) {}

    string getMovieId() const { return movieId; }
    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDurationMinutes() const { return durationMinutes; }
};
#endif
