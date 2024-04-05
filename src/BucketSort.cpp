#include "BucketSort.h"
#include <algorithm>
#include <vector>

void BucketSort::sort(std::vector<Movie>& arr) {
    if (arr.empty()) return;

    const int num_buckets = 10; 
    std::vector<std::list<Movie>> buckets(num_buckets);

    for (const auto& movie : arr) {
        int bucket_index = static_cast<int>(movie.rating * num_buckets / 10.0); 
        bucket_index = std::min(bucket_index, num_buckets - 1); // Zapewnia, że rating 10.0 trafia do ostatniego kubełka
        buckets[bucket_index].push_back(movie);
    }

    for (auto& bucket : buckets) {
        bucket.sort([](const Movie& a, const Movie& b) {
            return a.rating < b.rating; // Sortowanie rosnąco wewnątrz kubełków
        });
    }

    auto arr_it = arr.begin();
    for (const auto& bucket : buckets) {
        for (const auto& movie : bucket) {
            *arr_it++ = movie;
        }
    }
}