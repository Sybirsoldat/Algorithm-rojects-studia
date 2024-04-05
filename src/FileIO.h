#ifndef FILEIO_H
#define FILEIO_H

#include "Movie.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class FileIO {
public:
    static std::vector<Movie> readData(const std::string& filePath);
    static void writeData(const std::string& filePath, const std::vector<Movie>& movies);
};

#endif // FILEIO_H