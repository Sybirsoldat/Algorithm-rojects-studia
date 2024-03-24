#include "FileIO.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<int> FileIO::readNumbersFromFile(const std::string& filePath) {
    std::vector<int> numbers;
    std::ifstream file(filePath);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream iss(line);
            int number;
            while (iss >> number) {
                numbers.push_back(number);
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    return numbers;
}

void FileIO::writeNumbersToFile(const std::string& filePath, const std::vector<int>& numbers) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        for (const int& number : numbers) {
            file << number << "\n";
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
}
