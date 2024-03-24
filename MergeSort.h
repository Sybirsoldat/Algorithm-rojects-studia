#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortStrategy.h"

class MergeSort : public SortStrategy {
public:
    void sort(std::vector<int>& arr) override;
private:
    void merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right);
};

#endif