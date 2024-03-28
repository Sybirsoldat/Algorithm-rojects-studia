#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// Helper function to reverse the format from ID,Name,Rating to Rating,Name,ID
std::string reverseFormat(const std::string& line) {
    std::istringstream iss(line);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(iss, segment, ',')) {
        seglist.push_back(segment);
    }

    // Assuming the format is always ID,Name,Rating
    if (seglist.size() == 3) {
        return seglist[2] + "," + seglist[1] + "," + seglist[0]; // Rating,Name,ID
    }
    return ""; // Return empty string if the format does not match
}

std::vector<std::string> FileIO::readData(const std::string& filePath) {
    std::vector<std::string> data;
    std::ifstream file(filePath);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            std::string formattedLine = reverseFormat(line);
            if (!formattedLine.empty()) {
                data.push_back(formattedLine);
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filePath << std::endl;
    }
    return data;
}

void FileIO::writeData(const std::string& filePath, const std::vector<std::string>& data) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        for (const auto& line : data) {
            file << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filePath << std::endl;
    }
}