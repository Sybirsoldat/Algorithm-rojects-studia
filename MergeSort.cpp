#include "MergeSort.h"

void MergeSort::sort(std::vector<std::string>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        std::vector<std::string> left(arr.begin(), arr.begin() + mid);
        std::vector<std::string> right(arr.begin() + mid, arr.end());
        sort(left);
        sort(right);
        merge(arr, left, right);
    }
}

void MergeSort::merge(std::vector<std::string>& arr, std::vector<std::string>& left, std::vector<std::string>& right) {
    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (getRating(left[i]) < getRating(right[j])) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}