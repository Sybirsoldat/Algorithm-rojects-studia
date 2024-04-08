#include <chrono>
// Funkcja testująca czas wykonania funkcji test_func.
template<typename TimeUnit, typename F> 
int test_time(F&& test_func) {
  // Pobranie czasu startu
  auto start = std::chrono::high_resolution_clock::now();
  // Wywołanie funkcji test_func
  test_func();
  // Pobranie czasu zakończenia
  auto end = std::chrono::high_resolution_clock::now();
  // Obliczenie czasu trwania
  auto duration = std::chrono::duration_cast<TimeUnit>(end - start);
  // Zwrócenie czasu trwania w odpowiedniej jednostce
  return duration.count();
}