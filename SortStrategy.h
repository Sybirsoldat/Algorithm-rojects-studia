#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include <vector>

class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(std::vector<int>& arr) = 0;
};

#endif