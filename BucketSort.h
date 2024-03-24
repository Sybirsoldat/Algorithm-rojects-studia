#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include "SortStrategy.h"

class BucketSort : public SortStrategy {
public:
    void sort(std::vector<int>& arr) override;
private:
    void insertionSort(std::vector<int>& arr);
};

#endif