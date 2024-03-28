#include "BucketSort.h"

void BucketSort::sort(std::vector<std::string>& arr) {
    // Tworzenie 10 kubełków dla ratingów od 1 do 10
    std::vector<std::list<std::string>> buckets(10);

    // Przypisanie stringów do odpowiednich kubełków na podstawie ich ratingu
    for (const auto& str : arr) {
        int rating = getRating(str); // Zakładamy, że getRating zwraca wartość ratingu z zakresu 1-10
        if (rating >= 1 && rating <= 10) {
            buckets[rating - 1].push_back(str); // Rating 1 trafia do buckets[0], rating 10 do buckets[9]
        }
    }

    // Zbieranie posortowanych danych z kubełków i zapisywanie ich z powrotem do arr
    int index = 0;
    for (auto& bucket : buckets) {
        for (const auto& str : bucket) {
            arr[index++] = str;
        }
    }
}