#include "Memory_pool.h"

class Test {
public :
    int a;
    double b;
public:
    Test(int a, double b) : a(a), b(b) {
        std::cout << " a = " << a << std::endl;
        std::cout << " b = " << b << std::endl;
    }
    ~Test()
    {

    }
};



int main() {
    MemoryPool<int> pool(10);

    std::cout << "Allocating 2 blocks..." << std::endl;
    int* p1 = pool.newElement(3);
    int* p2 = pool.newElement(3);


    std::cout << "Allocated addresses: " << p1 << ", " << p2 << std::endl;
    std::cout << "Allocated elements: " << *(p1) << ", " << *(p2) << std::endl;

    std::cout << "Deallocating 1 blocks..." << std::endl;
    pool.deleteElement(p1);

    std::cout << "Allocating 2 more blocks..." << std::endl;
    int* p3 = pool.newElement(10);
    int* p4 = pool.newElement(11);

    std::cout << "New allocated addresses: " << p3 << ", " << p4 << std::endl;
    std::cout << "Allocated elements: " << *(p3) << ", " << *(p4) << std::endl;

    pool.deleteElement(p2);
    pool.deleteElement(p3);
    pool.deleteElement(p4);

    std::cout << "new test  *********************************************" << std::endl;

    MemoryPool<Test> pool2(10);

     Test* my_ptr = pool2.newElement(5, 6.6);
     std::cout << "Int ptr :" << my_ptr << std::endl;
     std::cout << "The elements : " << my_ptr->a << " , " << my_ptr->b << std::endl;


     pool2.deleteElement(my_ptr);

    return 0;
}
