#ifndef LazySum_H_
#define LazySum_H_

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <type_traits>

template <typename Container, typename T = typename Container::value_type>
class LazySum {
private:
    const Container& a;
    const Container& b;

public:

    LazySum(const Container& cont1, const Container& cont2);

    ~LazySum();

    T operator[](size_t index) const;

};

#endif // !LazySum_H_

