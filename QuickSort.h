#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortStrategy.h"

class QuickSort : public SortStrategy {
public:
    void sort(std::vector<std::string>& arr) override; // Zmienione z std::vector<int>
private:
    void quicksort(std::vector<std::string>& arr, int low, int high);
    int partition(std::vector<std::string>& arr, int low, int high);
};

#endif
