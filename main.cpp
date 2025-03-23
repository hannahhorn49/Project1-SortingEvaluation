#include <iostream>
#include "vector_sorter.hpp"

bool test_vector_merge_sort();
bool test_vector_quick_sort();
bool test_vector_insertion_sort();
bool test_list_merge_sort();

int main()
{
    if (test_vector_merge_sort())
        std::cout << "All Merge Sort tests passed!!\n";

    if (test_vector_quick_sort())
        std::cout << "All Quick Sort tests passed!!\n";

    if (test_vector_insertion_sort())
    {
        std::cout << "All Insertion Sort tests passed!!\n";
    }
    if (test_list_merge_sort())
    {
        std::cout << "All Merge Sort tests for Linked Lists Passed!!\n";
    }
    return 0;
}