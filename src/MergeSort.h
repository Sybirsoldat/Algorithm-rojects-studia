#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortStrategy.h"

class MergeSort : public SortStrategy {
public:
    void sort(std::vector<Movie>& arr) override;
private:
    void merge(std::vector<Movie>& arr, std::vector<Movie>& left, std::vector<Movie>& right);
};

#endif // MERGESORT_H