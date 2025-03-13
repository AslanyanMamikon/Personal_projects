#include <iostream>
using namespace std;

template <typename t>
class vector {

private:
    size_t size;
    size_t capacity;
    t* data;
public :
    vector() {
        size = 0;
        capacity = 1;

        data = (t*)malloc(capacity * sizeof(t));
        if (!data) throw bad_alloc();
    }

    vector(size_t n, const t& value) {
        size = n;
        capacity = n;
        data = (t*)malloc(capacity * sizeof(t));
        if (!data) throw bad_alloc();

        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    vector(initializer_list<t> init) {
        size = init.size();
        capacity = init.size();

        data = (t*)malloc(capacity * sizeof(t));
        if (!data) throw bad_alloc();

        size_t i = 0;

        for (const t& elem : init) {
            data[i] = elem;
            i++;
        }
    }

    vector(const vector& other) {
        size = other.size;
        capacity = other.capacity;

        data = (t*)malloc(capacity * sizeof(t));
        if (!data) throw bad_alloc();
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~vector() {
        free(data); 
    }

    size_t SIZE() { return size; }

    t& begin() {
        if (size == 0) {
            throw out_of_range("Vector is empaty");
        }

        return data[0];
    }

    t& end() {
        if (size == 0) {
            throw out_of_range("Vector is empaty");
        }

        return data[size - 1];
    }

    void push_back(const t& elem) {
        if (size == capacity) {
            capacity *= 2;
            data = (t*)realloc(data, capacity * sizeof(t));
            if (!data) throw bad_alloc();
        }

        data[size] = elem;
        size++;
    }

    void pop_back() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }

        size--;
    }

    void clear() {
        capacity = 1;
        size = 0;

        free(data);
        data = (t*)malloc(capacity * sizeof(t));
        if (!data) throw bad_alloc();
    }

    t& operator[](int index) {

        if (index >= size || index < 0) {
            throw out_of_range("Index is out of range");
        }
        return data[index];
    }

    vector& operator=(const vector& other) {
        if (this != &other) {
            free(data);
            size = other.size;
            capacity = other.capacity;
            data = (t*)malloc(capacity * sizeof(t));
            if (!data) throw bad_alloc();

            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }
};


int main()
{
    vector<int> vec;

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    cout << "First element: " << vec.begin() << endl;
    cout << "Last element: " << vec.end() << endl;
    vec.pop_back();

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    for (int i = 0; i < vec.SIZE(); i++) {
        cout << vec[i] << endl;
    }
    cout << "*****************" << endl;
    vector<int> vec1;
    vec1 = vec;
    for (int i = 0; i < vec.SIZE(); i++) {
        cout << vec1[i] << endl;
    }

    cout << "*****************" << endl;

    vector<char> v1(4, '0');
    vector<char> v2({'1','2','3', '4'});
    for (int i = 0; i < v1.SIZE(); i++) {
        cout << v1[i] << v2[i] << endl;
    }
    return 0;
}
