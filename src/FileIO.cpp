#include "FileIO.h"

std::vector<Movie> FileIO::readData(const std::string& filePath) {
    std::vector<Movie> movies;
    std::ifstream file(filePath);
    std::string line;
    
    // Pomijamy nagłówek
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string part, name, ratingStr;
        float rating;
        
        // Pomijanie ID
        std::getline(iss, part, ',');

        // Czytanie nazwy - uwzględniamy możliwość, że nazwa może zawierać przecinki
        name = line.substr(part.length() + 1, line.rfind(',') - part.length() - 1);

        // Czytanie oceny (ostatnia kolumna)
        ratingStr = line.substr(line.rfind(',') + 1);
        try {
            rating = std::stof(ratingStr);
            movies.push_back(Movie(name, rating));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error converting rating to number: " << e.what() << '\n';
        }
    }

    return movies;
}

void FileIO::writeData(const std::string& filePath, const std::vector<Movie>& movies) {
    std::ofstream file(filePath);

    for (const auto& movie : movies) {
        file << movie.name << "," << movie.rating << std::endl;
    }
}