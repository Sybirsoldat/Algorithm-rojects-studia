#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortStrategy.h"
#include <vector>
#include "Movie.h" 

class QuickSort : public SortStrategy {
public:
    
    void sort(std::vector<Movie>& arr) override;
};

#endif // QUICKSORT_H