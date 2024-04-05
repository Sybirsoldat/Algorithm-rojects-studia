#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortStrategy.h"

class QuickSort : public SortStrategy {
public:
    void sort(std::vector<Movie>& arr) override;
private:
    void quicksort(std::vector<Movie>& arr, int low, int high);
    int partition(std::vector<Movie>& arr, int low, int high);
};

#endif // QUICKSORT_H