#include <iostream>
#include "vector_sorter.hpp"
#include "evaluator.hpp"

bool test_vector_merge_sort();
bool test_vector_quick_sort();
bool testIngest();

int main()
{
    if (test_vector_merge_sort())
        std::cout << "All Merge Sort tests passed!!\n";

    if (test_vector_quick_sort())
        std::cout << "All Quick Sort tests passed!!\n";

    if (testIngest())
        std::cout << "Test Ingest passed!\n";

    return 0;
}