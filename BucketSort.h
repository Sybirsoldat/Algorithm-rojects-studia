#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include "SortStrategy.h"
#include <vector>
#include <string>
#include <list>

class BucketSort : public SortStrategy {
public:
    void sort(std::vector<std::string>& arr) override;
};

#endif