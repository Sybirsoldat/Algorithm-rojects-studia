#ifndef MOVIE_H
#define MOVIE_H

#include <string>
// Struktura reprezentująca danych
struct Movie {
    std::string name;
    float rating;
    // Konstruktor
    Movie(const std::string& name, float rating) : name(name), rating(rating) {}
    // Przeciążony operator `<` do sortowania
    bool operator<(const Movie& other) const {
        // Sortowanie rosnąco; zmień na `>` dla sortowania malejąco
        return rating < other.rating;
    }
};

#endif // MOVIE_H