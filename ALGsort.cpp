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
    std::vector<std::string> stringNumbers = FileIO::readData(inputFilePath);
    std::vector<int> numbers;
    numbers.reserve(stringNumbers.size());
    for (const auto& str : stringNumbers) {
        numbers.push_back(std::stoi(str));
    }

    std::unique_ptr<SortStrategy> sorter;
    int choice, howMany;

    std::cout << "Wybierz metodę sortowania:\n";
    std::cout << "1. Sortowanie przez scalanie (MergeSort)\n";
    std::cout << "2. Szybkie sortowanie (QuickSort)\n";
    std::cout << "3. Sortowanie kubełkowe (BucketSort)\n";
    std::cout << "Wybór: ";
    std::cin >> choice;

    std::cout << "Ile liczb chcesz posortować? (0 dla wszystkich): ";
    std::cin >> howMany;

    if (howMany <= 0 || howMany > numbers.size()) {
        howMany = numbers.size();
    }

    // Przygotowanie danych do sortowania (jeśli nie sortujemy wszystkich)
    std::vector<int> toSort(numbers.begin(), numbers.begin() + howMany);

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

    std::vector<int> toSort(numbers.begin(), numbers.begin() + howMany);

    sorter->sort(toSort);

    // Wyświetlanie posortowanych danych
    std::cout << "Posortowane dane:" << std::endl;
    for (const auto& num : toSort) {
        std::cout << num << std::endl;
    }

    // Zapis posortowanych danych do pliku
    FileIO::FileIO::writeData(outputFilePath, toSort);

    std::cout << "Dane zostały posortowane i zapisane do pliku: " << outputFilePath << std::endl;

    return 0;
}