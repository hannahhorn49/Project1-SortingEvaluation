#include <iostream>
#include "vector_sorter.hpp"

bool test_merge_sort();
bool test_quick_sort();

int main()
{
    if (test_merge_sort())
        std::cout << "Merge sort test passed!\n";
    else
        std::cout << "Merge sort test failed!\n";

    if (test_quick_sort())
        std::cout << "Quick sort test passed!\n";
    else
        std::cout << "Quick sort test failed!\n";

    return 0;
}