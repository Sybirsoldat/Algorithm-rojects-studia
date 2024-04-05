#ifndef MOVIE_H
#define MOVIE_H

#include <string>

struct Movie {
    std::string name;
    float rating;

    Movie(const std::string& name, float rating) : name(name), rating(rating) {}

    bool operator<(const Movie& other) const {
        // Sortowanie rosnąco; zmień na `>` dla sortowania malejąco
        return rating < other.rating;
    }
};

#endif // MOVIE_H