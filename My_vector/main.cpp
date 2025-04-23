
#include "My_vector.h"

int main()
{
    Vector<int> vec;

    // Test push_back and size
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Size after pushes: " << vec.size() << std::endl;

    // Test operator[]
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Test front and back
    std::cout << "Front: " << vec.front() << std::endl;
    std::cout << "Back: " << vec.back() << std::endl;

    // Test pop_back
    vec.pop_back();
    std::cout << "Size after pop: " << vec.size() << std::endl;

    // Test copy constructor
    Vector<int> vec2 = vec;
    std::cout << "Copied vector elements: ";
    for (size_t i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // Test clear
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;

    // Test initializer list constructor
    Vector<int> vec3 = { 1, 2, 3, 4, 5 };
    std::cout << "Initializer list vector elements: ";
    for (size_t i = 0; i < vec3.size(); i++) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
