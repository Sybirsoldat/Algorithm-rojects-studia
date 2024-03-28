#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(std::vector<std::string>& arr) = 0;

protected:
    static int getRating(const std::string& data) {
        std::istringstream iss(data);
        std::string ratingStr;
        std::getline(iss, ratingStr, ',');
        try {
            return std::stoi(ratingStr);
        } catch (const std::exception& e) {
            std::cerr << "Error converting Rating to integer: " << e.what() << std::endl;
            return -1; // Implement proper error handling or a default value
        }
    }
};

#endif