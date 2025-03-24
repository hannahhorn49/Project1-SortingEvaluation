#include <cassert>
#include <iostream>
#include "doubly_linked_list.hpp"

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

bool test_vector_insertion_sort()
{
    // set up:
    // case 1 (empty vector):
    std::vector<int> emptyVec;

    // case 2 (vector with one element)
    std::vector<int> one_element_vec{3};
    std::vector<int> expected_one{3};

    // rest of cases
    std::vector<int> my_vec1{3, 4, 5, 6};
    std::vector<int> exp_vec1{3, 4, 5, 6};

    std::vector<int> my_vec2{8, 5, 6, 8, 8};
    std::vector<int> exp_vec2{5, 6, 8, 8, 8}; // to test same values!

    std::vector<int> my_vec3{3, 4, 2, 1};
    std::vector<int> exp_vec3{1, 2, 3, 4};

    // EXECUTION
    VectorSorter::insertion_sort(my_vec1);
    VectorSorter::insertion_sort(my_vec2);
    VectorSorter::insertion_sort(my_vec3);

    // VALIDATION
    assert(emptyVec.size() == 0);
    assert(one_element_vec == expected_one);
    assert(my_vec1 == exp_vec1);
    assert(my_vec2 == exp_vec2);
    assert(my_vec3 == exp_vec3);

    // clean up
    return true;
}

bool test_list_merge_sort()
{
    // 1. set up
    DoublyLinkedList l;
    DoublyLinkedList empty;
    DoublyLinkedList oneItem;

    l.push_back(5);
    l.push_back(2);
    l.push_back(10);
    l.push_back(8);

    oneItem.push_back(64);

    DLLNode *l_head = l.get_head();
    DLLNode *empty_head = empty.get_head();
    DLLNode *oneItem_head = oneItem.get_head();

    // 2. execution
    DoublyLinkedList::DLL_merge_sort(l_head);
    DoublyLinkedList::DLL_merge_sort(empty_head);
    DoublyLinkedList::DLL_merge_sort(oneItem_head);

    // 3. validation
    assert(l_head->value == 2);
    assert(l_head->next->value == 5);
    assert(l_head->next->next->value == 8);
    assert(l_head->next->next->next->value == 10);
    assert(l_head->next->next->next->next == nullptr);
    DLLNode *l_tail = l.get_tail();
    assert(l_tail->value == 10);

    assert(empty.get_head() == nullptr);
    assert(empty.get_tail() == nullptr);

    assert(oneItem.get_head()->value == 64);
    assert(oneItem.get_head()->prev == nullptr);
    assert(oneItem.get_head()->next == nullptr);

    // 4. clean up
    return true;
}

bool test_list_insertion_sort()
{
    // 1. set up
    DoublyLinkedList no_nodes;
    DoublyLinkedList one_node;
    DoublyLinkedList multiple_nodes;

    one_node.push_back(18);

    multiple_nodes.push_back(27);
    multiple_nodes.push_back(38);
    multiple_nodes.push_back(34);
    multiple_nodes.push_back(15);

    DLLNode *no_nodes_head = no_nodes.get_head();
    DLLNode *one_node_head = one_node.get_head();
    DLLNode *multiple_nodes_head = multiple_nodes.get_head();

    // 2. execution
    no_nodes.DLL_insertion_sort(no_nodes_head);
    one_node.DLL_insertion_sort(one_node_head);
    multiple_nodes.DLL_insertion_sort(multiple_nodes_head);

    // 3. validation
    assert(no_nodes.get_head() == nullptr);
    assert(no_nodes.get_tail() == nullptr);

    assert(one_node.get_head()->value == 18);
    assert(one_node.get_head()->prev == nullptr);
    assert(one_node.get_head()->next == nullptr);

    assert(multiple_nodes_head->value == 15);
    assert(multiple_nodes_head->next->value == 27);
    assert(multiple_nodes_head->next->next->value == 34);
    assert(multiple_nodes_head->next->next->next->value == 38);
    assert(multiple_nodes_head->next->next->next->next == nullptr);
    DLLNode *multiple_nodes_tail = multiple_nodes.get_tail();
    assert(multiple_nodes_tail->value == 38);

    // 4. clean up
    return true;
}

bool test_list_quick_sort()
{
    // 1. set up
    DoublyLinkedList no_nodes;
    DoublyLinkedList one_node;
    DoublyLinkedList multiple_nodes;

    one_node.push_back(18);

    multiple_nodes.push_back(27);
    multiple_nodes.push_back(38);
    multiple_nodes.push_back(34);
    multiple_nodes.push_back(15);

    DLLNode *no_nodes_head = no_nodes.get_head();
    DLLNode *one_node_head = one_node.get_head();
    DLLNode *multiple_nodes_head = multiple_nodes.get_head();

    // 2. execution
    no_nodes.DLL_quick_sort(no_nodes_head);
    one_node.DLL_quick_sort(one_node_head);
    multiple_nodes.DLL_quick_sort(multiple_nodes_head);

    // 3. validation
    assert(no_nodes.get_head() == nullptr);
    assert(no_nodes.get_tail() == nullptr);

    assert(one_node.get_head()->value == 18);
    assert(one_node.get_head()->prev == nullptr);
    assert(one_node.get_head()->next == nullptr);

    assert(multiple_nodes_head->value == 15);
    assert(multiple_nodes_head->next->value == 27);
    assert(multiple_nodes_head->next->next->value == 34);
    assert(multiple_nodes_head->next->next->next->value == 38);
    assert(multiple_nodes_head->next->next->next->next == nullptr);
    DLLNode *multiple_nodes_tail = multiple_nodes.get_tail();
    assert(multiple_nodes_tail->value == 38);

    // 4. clean up
    return true;
}

