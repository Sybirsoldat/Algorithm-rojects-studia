#include "QuickSort.h"
#include <algorithm> // Dla std::swap
#include <cstdlib>   // Dla std::rand() i std::srand()
#include <ctime>     // Dla std::time()
#include <vector>
#include <stack>

void QuickSort::sort(std::vector<Movie>& arr) {
    // Inicjalizacja generatora liczb losowych jednokrotnie
    static const auto initializer = []() -> bool {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        return true;
    }();
    
    std::stack<std::pair<int, int>> stack;
    stack.push({0, static_cast<int>(arr.size()) - 1});

    while (!stack.empty()) {
        int start = stack.top().first, end = stack.top().second;
        stack.pop();

        if (start < end) {
            int lt = start, gt = end;
            Movie pivot = arr[start];
            int i = start;
            while (i <= gt) {
                if (arr[i].rating < pivot.rating) {
                    std::swap(arr[lt++], arr[i++]);
                } else if (arr[i].rating > pivot.rating) {
                    std::swap(arr[i], arr[gt--]);
                } else {
                    i++;
                }
            }

            if (lt - 1 > start) {
                stack.push({start, lt - 1});
            }
            if (gt + 1 < end) {
                stack.push({gt + 1, end});
            }
        }
    }
}