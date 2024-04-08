#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include "Movie.h"
#include <vector>

class SortStrategy {
public:
    // Wirtualny destruktor
    virtual ~SortStrategy() {}
    // Wirtualna metoda sortująca
    virtual void sort(std::vector<Movie>& arr) = 0;
};

#endif // SORTSTRATEGY_H