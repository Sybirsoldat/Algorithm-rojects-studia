#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include "SortStrategy.h"
#include <list>

class BucketSort : public SortStrategy {
public:
    void sort(std::vector<Movie>& arr) override;
};

#endif // BUCKETSORT_H