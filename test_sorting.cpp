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

bool test_vector_insertion_sort()
{
    //set up: 
    //case 1 (empty vector):
    std::vector<int> emptyVec;

    //case 2 (vector with one element)
    std::vector<int> one_element_vec{3};
    std::vector<int> expected_one{3};

    //rest of cases 
    std::vector<int> my_vec1{3,4,5,6};
    std::vector<int> exp_vec1{3,4,5,6};

    std::vector<int> my_vec2{8,5,6,8,8};
    std::vector<int> exp_vec2{5,6,8,8,8}; //to test same values!
    
    std::vector<int> my_vec3{3,4,2,1};
    std::vector<int> exp_vec3{1,2,3,4};

    //EXECUTION 
    VectorSorter::insertion_sort(my_vec1);
    VectorSorter::insertion_sort(my_vec2);
    VectorSorter::insertion_sort(my_vec3);

    //VALIDATION 
    assert(emptyVec.size() == 0);
    assert(one_element_vec == expected_one);
    assert(my_vec1 == exp_vec1);
    assert(my_vec2 == exp_vec2);
    assert(my_vec3 == exp_vec3);
    
    //clean up
    return true;
}

bool test_list_merge_sort(){
    //1. set up 

    //2. execution 

    //3. validation 

    //4. clean up
    return true;
}