#include "QuickSort.h"

void QuickSort::sort(std::vector<std::string>& arr) {
    quicksort(arr, 0, arr.size() - 1);
}

void QuickSort::quicksort(std::vector<std::string>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int QuickSort::partition(std::vector<std::string>& arr, int low, int high) {
    int pivotRating = getRating(arr[high]);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (getRating(arr[j]) < pivotRating) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}