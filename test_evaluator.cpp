#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <iostream>
#include <cassert>

// bool testIngest()
// {
//     // set up (create an instance of evaluator)
//     Evaluator evaluator;

//     // execution (call the ingest function)
//     evaluator.Ingest("evaluation_cases.txt");

//     // validation (part 1: vectors)
//     std::vector<std::vector<int>> expectedVectors = {
//         {1, 2, 7, 3}, {4, 5, 7, 7}, {1, 5, 8, 6}, {6, 1, 4, 0, 7}, {5, 3, 2, 4, 9}, {4, 1, 3, 0, 9}, {7, 3, 6, 5, 2, 5}, {8, 3, 5, 4, 8, 3}, {3, 0, 6, 4, 4, 9}};

//     const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();

//     assert(actualVectors.size() == expectedVectors.size());

//     for (int i = 0; i < expectedVectors.size(); ++i)
//     {
//         assert(actualVectors[i] == expectedVectors[i]);
//     }

//     std::cout << "Vector ingest test passed!\n";

//     // validation (part 2: doubly linked lists)

//     // created expected doubly linked lists from the expectedVectors
//     std::vector<DoublyLinkedList> expectedLists;
//     for (const auto &vec : expectedVectors)
//     {
//         DoublyLinkedList list;
//         for (int val : vec)
//         {
//             list.push_back(val);
//         }
//         expectedLists.push_back(list);
//     }

//     // get actual doubly linked lists from evaluator
//     const std::vector<DoublyLinkedList> &actualLists = evaluator.getTestLists();

//     assert(actualLists.size() == expectedLists.size());

//     // validate size for each doubly linked list
//     for (int i = 0; i < expectedLists.size(); ++i)
//     {
//         assert(expectedLists[i].size() == actualLists[i].size());
//     }

//     // for debugging print the lists!!
//     for (int i = 0; i < expectedLists.size(); ++i)
//     {
//         std::cout << "Expected List " << i << ": ";
//         expectedLists[i].print_list();
//         std::cout << "Actual List " << i << ": ";
//         actualLists[i].print_list();
//     }

//     std::cout << "Linked list ingest test passed!\n";

//     return true;
// }

bool testQuickComparison()
{
    // set up
    Evaluator evaluator;

    // execution
    evaluator.Ingest("evaluation_cases.txt");
    evaluator.QuickComparison();

    // debugging step here
    // vectors & lists
    const std::vector<std::vector<int>> &actualV100 = evaluator.getTestVectors100();
    const std::vector<DoublyLinkedList> &actualL100 = evaluator.getTestLists100();
    const std::vector<std::vector<int>> &actualV1000 = evaluator.getTestVectors1000();
    const std::vector<DoublyLinkedList> &actualL1000 = evaluator.getTestLists1000();
    const std::vector<std::vector<int>> &actualV10000 = evaluator.getTestVectors10000();
    const std::vector<DoublyLinkedList> &actualL10000 = evaluator.getTestLists10000();

    // timing here
    const std::vector<double> &actualVT100 = evaluator.getVectorTimingData100();
    const std::vector<double> &actualLT100 = evaluator.getListTimingData100();
    const std::vector<double> &actualVT1000 = evaluator.getVectorTimingData1000();
    const std::vector<double> &actualLT1000 = evaluator.getListTimingData1000();
    const std::vector<double> &actualVT10000 = evaluator.getVectorTimingData10000();
    const std::vector<double> &actualLT10000 = evaluator.getListTimingData10000();

    // validation (part 1: vectors)
    assert(actualV100.size() == 4);
    assert(actualV1000.size() == 4);
    assert(actualV10000.size() == 4);
    std::cout << "validation for vector size passed" << std::endl;

    assert(actualL100.size() == 4);
    assert(actualL1000.size() == 4);
    assert(actualL10000.size() == 4);

    for (const auto &list : actualL100)
        assert(list.size() == 100);
    for (const auto &list : actualL1000)
        assert(list.size() == 1000);
    for (const auto &list : actualL10000)
        assert(list.size() == 10000);

    std::cout << "validation for list size passed" << std::endl;

    // TIMING DATA VALIDATION
    for (const auto &timing : actualVT100)
        assert(timing >= 0.0);
    for (const auto &timing : actualVT1000)
        assert(timing >= 0.0);
    for (const auto &timing : actualVT10000)
        assert(timing >= 0.0);
    std::cout << "VECTOR timing data validation passed.\n";

    for (const auto &timing : actualLT100)
        assert(timing >= 0.0);
    for (const auto &timing : actualLT1000)
        assert(timing >= 0.0);
    for (const auto &timing : actualLT10000)
        assert(timing >= 0.0);
    std::cout << "list timing data validation passed.\n";

    std::cout << "===================================\n";
    std::cout << "QuickComparison test passed!\n";

    return true;
}

bool testMergeComparison()
{
    // set up
    Evaluator evaluator;

    // execution
    evaluator.Ingest("evaluation_cases.txt");
    evaluator.MergeComparison();

    // debugging step here
    // vectors & lists
    const std::vector<std::vector<int>> &actualV100 = evaluator.getTestVectors100();
    const std::vector<DoublyLinkedList> &actualL100 = evaluator.getTestLists100();
    const std::vector<std::vector<int>> &actualV1000 = evaluator.getTestVectors1000();
    const std::vector<DoublyLinkedList> &actualL1000 = evaluator.getTestLists1000();
    const std::vector<std::vector<int>> &actualV10000 = evaluator.getTestVectors10000();
    const std::vector<DoublyLinkedList> &actualL10000 = evaluator.getTestLists10000();

    // timing here
    const std::vector<double> &actualVT100 = evaluator.getVectorTimingData100();
    const std::vector<double> &actualLT100 = evaluator.getListTimingData100();
    const std::vector<double> &actualVT1000 = evaluator.getVectorTimingData1000();
    const std::vector<double> &actualLT1000 = evaluator.getListTimingData1000();
    const std::vector<double> &actualVT10000 = evaluator.getVectorTimingData10000();
    const std::vector<double> &actualLT10000 = evaluator.getListTimingData10000();

    // validation (part 1: vectors)
    assert(actualV100.size() == 4);
    assert(actualV1000.size() == 4);
    assert(actualV10000.size() == 4);
    std::cout << "validation for vector size passed" << std::endl;

    assert(actualL100.size() == 4);
    assert(actualL1000.size() == 4);
    assert(actualL10000.size() == 4);

    for (const auto &list : actualL100)
        assert(list.size() == 100);
    for (const auto &list : actualL1000)
        assert(list.size() == 1000);
    for (const auto &list : actualL10000)
        assert(list.size() == 10000);

    std::cout << "validation for list size passed" << std::endl;

    // TIMING DATA VALIDATION
    for (const auto &timing : actualVT100)
        assert(timing >= 0.0);
    for (const auto &timing : actualVT1000)
        assert(timing >= 0.0);
    for (const auto &timing : actualVT10000)
        assert(timing >= 0.0);
    std::cout << "VECTOR timing data validation passed.\n";

    for (const auto &timing : actualLT100)
        assert(timing >= 0.0);
    for (const auto &timing : actualLT1000)
        assert(timing >= 0.0);
    for (const auto &timing : actualLT10000)
        assert(timing >= 0.0);
    std::cout << "list timing data validation passed.\n";

    std::cout << "===================================\n";
    std::cout << "MergeComparison test passed!\n";

    return true;
}

bool testInsertionComparison()
{
    // set up
    Evaluator evaluator;

    // execution
    evaluator.Ingest("evaluation_cases.txt");
    evaluator.InsertionComparison();

    // debugging step here
    // vectors & lists
    const std::vector<std::vector<int>> &actualV100 = evaluator.getTestVectors100();
    const std::vector<DoublyLinkedList> &actualL100 = evaluator.getTestLists100();
    const std::vector<std::vector<int>> &actualV1000 = evaluator.getTestVectors1000();
    const std::vector<DoublyLinkedList> &actualL1000 = evaluator.getTestLists1000();
    const std::vector<std::vector<int>> &actualV10000 = evaluator.getTestVectors10000();
    const std::vector<DoublyLinkedList> &actualL10000 = evaluator.getTestLists10000();

    // timing here
    const std::vector<double> &actualVT100 = evaluator.getVectorTimingData100();
    const std::vector<double> &actualLT100 = evaluator.getListTimingData100();
    const std::vector<double> &actualVT1000 = evaluator.getVectorTimingData1000();
    const std::vector<double> &actualLT1000 = evaluator.getListTimingData1000();
    const std::vector<double> &actualVT10000 = evaluator.getVectorTimingData10000();
    const std::vector<double> &actualLT10000 = evaluator.getListTimingData10000();

    // validation (part 1: vectors)
    assert(actualV100.size() == 4);
    assert(actualV1000.size() == 4);
    assert(actualV10000.size() == 4);
    std::cout << "validation for vector size passed" << std::endl;

    assert(actualL100.size() == 4);
    assert(actualL1000.size() == 4);
    assert(actualL10000.size() == 4);

    for (const auto &list : actualL100)
        assert(list.size() == 100);
    for (const auto &list : actualL1000)
        assert(list.size() == 1000);
    for (const auto &list : actualL10000)
        assert(list.size() == 10000);

    std::cout << "validation for list size passed" << std::endl;

    // TIMING DATA VALIDATION
    for (const auto &timing : actualVT100)
        assert(timing >= 0.0);
    for (const auto &timing : actualVT1000)
        assert(timing >= 0.0);
    for (const auto &timing : actualVT10000)
        assert(timing >= 0.0);
    std::cout << "VECTOR timing data validation passed.\n";

    for (const auto &timing : actualLT100)
        assert(timing >= 0.0);
    for (const auto &timing : actualLT1000)
        assert(timing >= 0.0);
    for (const auto &timing : actualLT10000)
        assert(timing >= 0.0);
    std::cout << "list timing data validation passed.\n";

    std::cout << "===================================\n";
    std::cout << "InsertionComparison test passed!\n";

    return true;
}

// call each test function here
// bool testIngest();
bool testMergeComparison();
bool testQuickComparison();
bool testInsertionComparison();

int main()
{
    std::cout << "Running Evaluator Tests...\n";

    // if (testIngest())
    // {
    //     std::cout << "Ingest test passed!\n";
    // }
    // else
    // {
    //     std::cout << "Ingest test failed!\n";
    // }

    if (testMergeComparison())
    {
        std::cout << "MergeComparison test passed!\n";
    }
    else
    {
        std::cout << "MergeComparison test failed!\n";
    }

    if (testQuickComparison())
    {
        std::cout << "QuickComparison test passed!\n";
    }
    else
    {
        std::cout << "QuickComparison test failed!\n";
    }

    if (testInsertionComparison())
    {
        std::cout << "InsertionComparison test passed!\n";
    }
    else
    {
        std::cout << "InsertionComparison test failed!\n";
    }

    return 0;
}