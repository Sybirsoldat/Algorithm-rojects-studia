#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include "Movie.h"
#include <vector>

class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(std::vector<Movie>& arr) = 0;
};

#endif // SORTSTRATEGY_H