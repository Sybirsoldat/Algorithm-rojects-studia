#include "MergeSort.h"
#include "QuickSort.h"
#include "BucketSort.h"
#include "FileIO.h"
#include "Movie.h"
#include "test_time.h"
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <fstream>


typedef std::chrono::milliseconds milli;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path> <output_file_path>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];

    // Wczytanie danych z pliku do wektora struktur Movie
    auto movies = FileIO::readData(inputFilePath);

    std::unique_ptr<SortStrategy> sorter;
    int choice, sizeChoice, numOfTests;

    std::cout << "Wybierz metodę sortowania:\n";
    std::cout << "1. Sortowanie przez scalanie (MergeSort)\n";
    std::cout << "2. Szybkie sortowanie (QuickSort)\n";
    std::cout << "3. Sortowanie kubełkowe (BucketSort)\n";
    std::cout << "Wybór: ";
    std::cin >> choice;

    std::cout << "Wybierz zakres danych do sortowania:\n";
    std::cout << "1. Pierwsze 10 000\n";
    std::cout << "2. Pierwsze 100 000\n";
    std::cout << "3. Pierwsze 250 000\n";
    std::cout << "4. Pierwsze 500 000\n";
    std::cout << "5. Pierwsze 750 000\n";
    std::cout << "6. Pierwsze 1 000 000\n";
    std::cout << "7. Maksymalna ilość danych\n";
    std::cout << "Wybór: ";
    std::cin >> sizeChoice;

    std::cout << "Podaj liczbę testów do wykonania: ";
    std::cin >> numOfTests;

    std::string algorithmName; // Zmienna do przechowywania nazwy algorytmu

    // Przygotowanie odpowiedniego sortera w zależności od wyboru użytkownika
    switch (choice) {
        case 1:
            sorter = std::make_unique<MergeSort>();
            algorithmName = "MergeSort";
            break;
        case 2:
            sorter = std::make_unique<QuickSort>();
            algorithmName = "QuickSort";
            break;
        case 3:
            sorter = std::make_unique<BucketSort>();
            algorithmName = "BucketSort";
            break;
        default:
            std::cerr << "Niepoprawny wybór!" << std::endl;
            return 1;
    }

    // Ograniczenie danych do wybranego zakresu
    size_t dataSize;
    switch (sizeChoice) {
        case 1:
            dataSize = 10000;
            break;
        case 2:
            dataSize = 100000;
            break;
        case 3:
            dataSize = 250000;
            break;
        case 4:
            dataSize = 500000;
            break;
        case 5:
            dataSize = 750000;
            break;
        case 6:
            dataSize = 1000000;
            break;
        case 7:
            dataSize = movies.size();
            break;
        default:
            std::cerr << "Niepoprawny wybór zakresu!" << std::endl;
            return 1;

    }
    dataSize = std::min(dataSize, movies.size());

    // Otwarcie pliku do dopisywania danych
    std::ofstream testTimeFile("test_time.txt", std::ios::app); 

    for (int i = 0; i < numOfTests; ++i) {
        // Kopiujemy dane i ograniczamy do wybranego rozmiaru
        std::vector<Movie> moviesCopy(movies.begin(), movies.begin() + dataSize);
        int time = test_time<milli>([&sorter, &moviesCopy]() { sorter->sort(moviesCopy); });

        testTimeFile << "Test #" << i + 1 << ": " << time << "ms dla " << dataSize << " danych, używając " << algorithmName << "." << std::endl;
    }

    testTimeFile.close();

    // Sortowanie danych
    sorter->sort(movies);

    // Zapis posortowanych danych do pliku
    FileIO::writeData(outputFilePath, movies);

    std::cout << "Dane zostały posortowane i zapisane do pliku: " << outputFilePath << std::endl;
    std::cout << "Wyniki czasu wykonania zostały zapisane do pliku test_time.txt" << std::endl;


    return 0;
}