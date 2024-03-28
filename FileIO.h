#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>

class FileIO {
public:
    // Methods for handling integer data
    static std::vector<int> readNumbersFromFile(const std::string& filePath);
    static void writeNumbersToFile(const std::string& filePath, const std::vector<int>& numbers);
    
    // New methods for handling string data in the format "Rating,Name,ID"
    static std::vector<std::string> readData(const std::string& filePath);
    static void writeData(const std::string& filePath, const std::vector<std::string>& data);
};

#endif // FILEIO_H
