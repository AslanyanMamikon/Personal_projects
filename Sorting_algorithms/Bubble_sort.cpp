
#include <iostream>
#include <vector>


void bubbleSort(std::vector<int>& a) {
    for (size_t i = 0; i < a.size() - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < a.size() - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

//template<typename Iterator>
//void bubbleSort(Iterator begin, Iterator end)
//{
//    Iterator lastUnordered = end;
//    for (Iterator i = begin; i != end; ++i) {
//        bool swapped = false;
//        for (Iterator it = begin; std::next(it) != lastUnordered; ++it) {
//            Iterator nextIt = std::next(it);
//            if (*it > *nextIt) {
//                std::swap(*it, *nextIt);
//                swapped = true;
//            }
//        }
//        --lastUnordered;
//        if (!swapped) break;
//    }
//}

int main()
{
    std::vector<int> a = { 1,2,3,15,1,4,55,8,9 };
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << "   ";
    }

    //bubbleSort(a.begin(), a.end());
    bubbleSort(a);
    std::cout << std::endl << "new-----------" << std::endl;
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << "   ";
    }
    return 0;
}
