
#include <iostream>
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

int main()
{
    SingleLinkedList<int> list;

    // Test push operations
    list.push_front(1);
    list.push_back(2);
    list.push_back(3);

    // Test size and traversal
    std::cout << "List size: " << list.size() << std::endl;
    std::cout << "List elements: ";
    for (auto node = list.first(); node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    // Test remove operation
    list.remove(2);
    std::cout << "After removing 2: ";
    for (auto node = list.first(); node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    // Test clear operation
    list.clear();
    std::cout << "Is list empty after clear? " << (list.empty() ? "Yes" : "No") << std::endl;

    // Test DoubleLinkedList
    std::cout << "\nTesting DoubleLinkedList:" << std::endl;
    DoubleLinkedList<int> dlist;

    // Test push operations
    dlist.push_front(1);
    dlist.push_back(2);
    dlist.push_back(3);

    // Test size and traversal
    std::cout << "List size: " << dlist.size() << std::endl;
    std::cout << "List elements forward: ";
    for (auto node = dlist.first(); node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    // Test reverse traversal
    std::cout << "List elements backward: ";
    for (auto node = dlist.last(); node != nullptr; node = node->prev) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    // Test remove operation
    dlist.remove(2);
    std::cout << "After removing 2: ";
    for (auto node = dlist.first(); node != nullptr; node = node->next) {
        std::cout << node->data << " ";
    }
    std::cout << std::endl;

    // Test clear operation
    dlist.clear();
    std::cout << "Is list empty after clear? " << (dlist.empty() ? "Yes" : "No") << std::endl;
    return 0;
}
