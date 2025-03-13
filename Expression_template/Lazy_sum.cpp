#include "Lazy_sum.h"

template <typename Container, typename T>
LazySum<Container, T>::LazySum(const Container& cont1, const Container& cont2) : a(cont1), b(cont2) {}

template <typename Container, typename T>
LazySum<Container, T>::~LazySum() {}

template <typename Container, typename T>
T LazySum<Container, T>::operator[](size_t index) const {
    if (index >= a.size() || index >= b.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return a[index] + b[index];
}


int main() {
    // Example with vector
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {9, 8, 7, 6, 5};
    LazySum<std::vector<int>> sum_vec(vec1, vec2);
    std::cout << "Vector sum at index 3: " << sum_vec[3] << std::endl;

    // Example with array
    std::array<int, 3> arr1 = {1, 2, 3};
    std::array<int, 3> arr2 = {4, 5, 6};
    LazySum<std::array<int, 3>> sum_arr(arr1, arr2);
    std::cout << "Array sum at index 1: " << sum_arr[1] << std::endl;

    // Example with deque
    std::deque<double> deq1 = {1.1, 2.2, 3.3};
    std::deque<double> deq2 = {0.1, 0.2, 0.3};
    LazySum<std::deque<double>> sum_deq(deq1, deq2);
    std::cout << "Deque sum at index 0: " << sum_deq[0] << std::endl;

    return 0;
}
