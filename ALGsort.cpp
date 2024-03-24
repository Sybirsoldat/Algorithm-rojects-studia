#include "MergeSort.h"
#include "QuickSort.h"
#include "BucketSort.h"
#include "FileIO.h"
#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file_path> <output_file_path>" << std::endl;
        return 1;
    }

    std::string inputFilePath = argv[1];
    std::string outputFilePath = argv[2];

    // Wczytanie danych z pliku
    std::vector<int> numbers = FileIO::readNumbersFromFile(inputFilePath);

    std::unique_ptr<SortStrategy> sorter;
    int choice;

    std::cout << "Wybierz metodę sortowania:\n";
    std::cout << "1. Sortowanie przez scalanie (MergeSort)\n";
    std::cout << "2. Szybkie sortowanie (QuickSort)\n";
    std::cout << "3. Sortowanie kubełkowe (BucketSort)\n";
    std::cout << "Wybór: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            sorter = std::make_unique<MergeSort>();
            break;
        case 2:
            sorter = std::make_unique<QuickSort>();
            break;
        case 3:
            sorter = std::make_unique<BucketSort>();
            break;
        default:
            std::cerr << "Niepoprawny wybór!" << std::endl;
            return 1;
    }

    sorter->sort(numbers);

    // Zapis posortowanych danych do pliku
    FileIO::writeNumbersToFile(outputFilePath, numbers);

    std::cout << "Dane zostały posortowane i zapisane do pliku: " << outputFilePath << std::endl;

    return 0;
}
