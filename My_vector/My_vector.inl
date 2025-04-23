#ifndef MyVector_INL_
#define MyVector_INL_

template <typename T>
Vector<T>::Vector() : size_(0), capacity_(1) {
    data_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
    if (!data_) throw std::bad_alloc();
}

template <typename T>
Vector<T>::Vector(size_t n, const T& value) : size_(n), capacity_(n) {
    data_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
    if (!data_) throw std::bad_alloc();

    for (size_t i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init) : size_(init.size()), capacity_(init.size()) {
    data_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
    if (!data_) throw std::bad_alloc();
    
    std::copy(init.begin(), init.end(), data_);
}

template <typename T>
Vector<T>::Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
    std::shared_lock<std::shared_mutex> lock(other.mutex_);
    data_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
    if (!data_) throw std::bad_alloc();
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <typename T>
Vector<T>::~Vector() {
    free(data_);
}

template <typename T>
size_t Vector<T>::size() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return size_;
}

template <typename T>
size_t Vector<T>::capacity() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return capacity_;
}

template <typename T>
T& Vector<T>::front() {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    if (size_ == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data_[0];
}

template <typename T>
T& Vector<T>::back() {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    if (size_ == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data_[size_ - 1];
}

template <typename T>
void Vector<T>::push_back(const T& elem) {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    if (size_ == capacity_) {
        capacity_ *= 2;
        data_ = static_cast<T*>(realloc(data_, capacity_ * sizeof(T)));
        if (!data_) throw std::bad_alloc();
    }
    data_[size_] = elem;
    size_++;
}

template <typename T>
void Vector<T>::pop_back() {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    if (size_ == 0) {
        throw std::out_of_range("Vector is empty");
    }
    size_--;
}

template <typename T>
void Vector<T>::clear() {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    capacity_ = 1;
    size_ = 0;
    free(data_);
    data_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
    if (!data_) throw std::bad_alloc();
}

template <typename T>
T& Vector<T>::operator[](int index) {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Index is out of range");
    }
    return data_[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        std::unique_lock<std::shared_mutex> lock_this(mutex_, std::defer_lock);
        std::shared_lock<std::shared_mutex> lock_other(other.mutex_, std::defer_lock);
        std::lock(lock_this, lock_other);

        free(data_);
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
        if (!data_) throw std::bad_alloc();

        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

#endif // !MyVector_INL_
