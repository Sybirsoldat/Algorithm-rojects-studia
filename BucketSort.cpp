#include "BucketSort.h"

void BucketSort::sort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int maxVal = arr[0];
    int minVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    int bucketSize = maxVal - minVal + 1;
    std::vector<std::vector<int>> bucket(bucketSize);
    
    for (int num : arr) {
        bucket[num - minVal].push_back(num);
    }

    int index = 0;
    for (auto& b : bucket) {
        insertionSort(b); // Użyj prostego sortowania wstawiania dla kubełków
        for (int num : b) {
            arr[index++] = num;
        }
    }
}

void BucketSort::insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}