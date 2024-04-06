#include <chrono>
template<typename TimeUnit, typename F>
int test_time(F&& test_func) {
  auto start = std::chrono::high_resolution_clock::now();
  test_func();
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<TimeUnit>(end - start);
  return duration.count();
}