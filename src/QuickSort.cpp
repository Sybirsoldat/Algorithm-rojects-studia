#include "QuickSort.h"
#include <algorithm> // Dla std::swap
#include <vector>
#include <stack>

void QuickSort::sort(std::vector<Movie>& arr) {
    // Pomijamy niezastosowane parametry
    std::stack<std::pair<int, int>> stack;
    stack.push({0, static_cast<int>(arr.size()) - 1});
    // Iteracyjne sortowanie szybkie
    while (!stack.empty()) {
        int start = stack.top().first, end = stack.top().second;
        stack.pop();
        // Jeśli są co najmniej 2 elementy
        if (start < end) {
            // Losowy wybór elementu rozdzielającego    
            int lt = start, gt = end;
            // Losowy element rozdzielający
            Movie pivot = arr[start];
            // Przeszukiwanie tablicy
            int i = start;
            while (i <= gt) {
                // Porównanie z elementem rozdzielającym
                if (arr[i].rating < pivot.rating) {
                    std::swap(arr[lt++], arr[i++]);
                } else if (arr[i].rating > pivot.rating) {
                    std::swap(arr[i], arr[gt--]);
                } else {
                    i++;
                }
            }
            // Rekurencyjne sortowanie lewej i prawej części
            if (lt - 1 > start) {
                stack.push({start, lt - 1});
            }
            if (gt + 1 < end) {
                stack.push({gt + 1, end});
            }
        }
    }
}