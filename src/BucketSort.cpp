#include "BucketSort.h"
#include <algorithm>
#include <vector>

// Sortowanie kubełkowe
void BucketSort::sort(std::vector<Movie>& arr) {
    if (arr.empty()) return;

    // Tworzenie kubełków
    const int num_buckets = 10; 
    std::vector<std::list<Movie>> buckets(num_buckets);

    // Rozrzucanie elementów do kubełków
    for (const auto& movie : arr) {
        int bucket_index = static_cast<int>(movie.rating * num_buckets / 10.0); // Przeliczanie ratingu na indeks kubełka
        bucket_index = std::min(bucket_index, num_buckets - 1); // Zapewnia, że rating 10.0 trafia do ostatniego kubełka
        buckets[bucket_index].push_back(movie); // Dodawanie filmu do odpowiedniego kubełka
    }
    // Sortowanie kubełków
    for (auto& bucket : buckets) {
        bucket.sort([](const Movie& a, const Movie& b) {
            return a.rating < b.rating; // Sortowanie rosnąco wewnątrz kubełków
        });
    }
    // Przygotowanie iteratora do zapisu posortowanych elementów
    auto arr_it = arr.begin(); 
    for (const auto& bucket : buckets) {
        // Kopiowanie posortowanych elementów z kubełka do tablicy
        for (const auto& movie : bucket) {
            // Zapisywanie posortowanych elementów do tablicy
            *arr_it++ = movie;
        }
    }
}