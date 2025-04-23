#ifndef MyVector_H_
#define MyVector_H_

#include <iostream>
#include <initializer_list>
#include <shared_mutex>
#include <mutex>

template <typename T>
class Vector {
private:
    size_t size_;
    size_t capacity_;
    T* data_;

    mutable std::shared_mutex mutex_;
public:
    // Constructors
    Vector();
    Vector(size_t n, const T& value);
    Vector(std::initializer_list<T> init);
    Vector(const Vector& other);

    // Destructor
    ~Vector();

    // Accessors
    size_t size() const;
    size_t capacity() const;
    T& front();
    T& back();

    // Modifiers
    void push_back(const T& elem);
    void pop_back();
    void clear();

    // Operators
    T& operator[](int index);
    Vector& operator=(const Vector& other);
};

#include "My_vector.inl"

#endif // !MyVector_H_
