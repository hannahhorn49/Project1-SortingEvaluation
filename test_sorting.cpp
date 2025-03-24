#include <cassert>
#include <iostream>
#include "vector_sorter.hpp"

bool test_vector_merge_sort()
{
    // set up
    // case 1 here (empty vector)
    std::vector<int> emptyVec;

    // case 2 here (single element vector)
    std::vector<int> singleVec = {42};

    // case 3 here (normal unsorted vector)
    std::vector<int> vec = {5, 0, 8, 1, 2};
    std::vector<int> expected = {0, 1, 2, 5, 8};

    // case 4 here (already sorted vector)
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};

    // execution -- calling merge sort
    VectorSorter::merge_sort(emptyVec);
    VectorSorter::merge_sort(singleVec);
    VectorSorter::merge_sort(vec);
    VectorSorter::merge_sort(sortedVec);

    // validation
    assert(emptyVec.size() == 0);
    std::cout << "Merge Passed Case 1: Empty Vector\n"; // note this one will pass bc empty vector doesn't require sorting

    assert(singleVec == std::vector<int>{42});
    std::cout << "Merge Passed Case 2: Single Element Vector\n"; // note this one will also pass bc a single element vector is inherently sorted

    assert(vec == expected);
    std::cout << "Merge Passed Case 3: Normal Unsorted vVctor\n";

    assert(sortedVec == expected2);
    std::cout << "Merge Passed Case 4: Already Sorted Vector\n";

    // clean up
    return true;
}

bool test_vector_quick_sort()
{
    // set up
    // case 1 (empty vector)
    std::vector<int> emptyVec;

    // case 2 (single element vector)
    std::vector<int> singleVec = {42};

    // case 3 (normal unsorted vector)
    std::vector<int> vec = {4, 7, 2, 9, 1, 5};
    std::vector<int> expected = {1, 2, 4, 5, 7, 9};

    // case 4 here (already sorted vector)
    std::vector<int> sortedVec = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};

    // execution
    VectorSorter::quick_sort(emptyVec);
    VectorSorter::quick_sort(singleVec);
    VectorSorter::quick_sort(vec);
    VectorSorter::quick_sort(sortedVec);

    // validation
    assert(emptyVec.size() == 0);
    std::cout << "Passed Case 1: Empty Vector\n";
    assert(singleVec == std::vector<int>{42});
    std::cout << "Passed Case 2: Single Element Vector\n";
    assert(vec == expected);
    std::cout << "Passed Case 3: Normal Unsorted vVctor\n";
    assert(sortedVec == expected2);
    std::cout << "Passed Case 4: Already Sorted Vector\n";

    // clean up
    return true;
}