#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortStrategy.h"

class QuickSort : public SortStrategy {
public:
    void sort(std::vector<int>& arr) override;
private:
    void quicksort(std::vector<int>& arr, int low, int high);
    int partition(std::vector<int>& arr, int low, int high);
};

#endif