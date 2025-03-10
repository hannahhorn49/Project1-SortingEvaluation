#include <cassert>
#include "vector_sorter.hpp"

bool test_merge_sort()
{
    // set up
    // case 1 here (empty vector)
    std::vector<int> emptyVec;

    // case 2 here (single element vector)
    std::vector<int> singleVec = {42};

    // case 3 here (normal unsorted vector)
    std::vector<int> vec = {5, 3, 8, 1, 2};
    std::vector<int> expected = {1, 2, 3, 5, 8};

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
    assert(singleVec == std::vector<int>{42});
    assert(vec == expected);
    assert(sortedVec == expected2);

    // clean up
    return true;
}

bool test_quick_sort()
{
    // set up
    // case 1 (empty vector)
    std::vector<int> emptyVec;

    // case 2 (single element vector)
    std::vector<int> singleVec = {42};

    // case 3 (normal unsorted vector)
    std::vector<int> vec = {9, 7, 5, 3, 1};
    std::vector<int> expected = {1, 3, 5, 7, 9};

    // execution
    VectorSorter::quick_sort(emptyVec);
    VectorSorter::quick_sort(singleVec);
    VectorSorter::quick_sort(vec);

    // validation
    assert(emptyVec.size() == 0);
    assert(singleVec == std::vector<int>{42});
    assert(vec == expected);

    // clean up
    return true;
}