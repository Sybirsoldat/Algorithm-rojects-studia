#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <string>

class FileIO {
public:
    static std::vector<int> readNumbersFromFile(const std::string& filePath);
    static void writeNumbersToFile(const std::string& filePath, const std::vector<int>& numbers);
};

#endif // FILEIO_H
