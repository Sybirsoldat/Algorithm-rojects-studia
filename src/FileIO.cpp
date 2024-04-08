#include "FileIO.h"

std::vector<Movie> FileIO::readData(const std::string& filePath) {
    std::vector<Movie> movies;
    std::ifstream file(filePath);
    std::string line;
    
    // Pomijamy nagłówek
    std::getline(file, line);
    // Czytanie danych
    while (std::getline(file, line)) {
        // Dzielenie linii na części
        std::istringstream iss(line);
        // Czytanie ID, nazwy i oceny
        std::string part, name, ratingStr;
        // Ocena jako liczba zmiennoprzecinkowa
        float rating;
        
        // Pomijanie pustego ID (czytamy do pierwszego przecinka i ignorujemy)
        std::getline(iss, part, ',');

        // Czytanie nazwy - uwzględniamy możliwość, że nazwa może zawierać przecinki
        name = line.substr(part.length() + 1, line.rfind(',') - part.length() - 1);

        // Czytanie oceny (ostatnia kolumna)
        ratingStr = line.substr(line.rfind(',') + 1);
        try {
            // Konwersja oceny na liczbę zmiennoprzecinkową
            rating = std::stof(ratingStr);
            
        } catch (const std::invalid_argument& e) {
            continue; // Pomijamy błędne wpisy
        }
        movies.push_back(Movie(name, rating));
    }

    return movies;
}
// Zapisywanie danych do pliku
void FileIO::writeData(const std::string& filePath, const std::vector<Movie>& movies) {
    std::ofstream file(filePath);
    // Nagłówek
    for (const auto& movie : movies) {
        file << movie.name << "," << movie.rating << std::endl;
    }
}