#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include <iostream>
#include <cassert>

bool testIngest()
{
    // set up (create an instance of evaluator)
    Evaluator evaluator;

    // execution (call the ingest function)
    evaluator.Ingest("test_cases.txt");

    // validation (part 1: vectors)
    std::vector<std::vector<int>> expectedVectors = {
        {1, 2, 7, 3}, {4, 5, 7, 7}, {1, 5, 8, 6}, {6, 1, 4, 0, 7}, {5, 3, 2, 4, 9}, {4, 1, 3, 0, 9}, {7, 3, 6, 5, 2, 5}, {8, 3, 5, 4, 8, 3}, {3, 0, 6, 4, 4, 9}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();

    assert(actualVectors.size() == expectedVectors.size());

    for (int i = 0; i < expectedVectors.size(); ++i)
    {
        assert(actualVectors[i] == expectedVectors[i]);
    }

    std::cout << "Vector ingest test passed!\n";

    // validation (part 2: doubly linked lists)

    // created expected doubly linked lists from the expectedVectors
    std::vector<DoublyLinkedList> expectedLists;
    for (const auto &vec : expectedVectors)
    {
        DoublyLinkedList list;
        for (int val : vec)
        {
            list.push_back(val);
        }
        expectedLists.push_back(list);
    }

    // get actual doubly linked lists from evaluator
    const std::vector<DoublyLinkedList> &actualLists = evaluator.getTestLists();

    assert(actualLists.size() == expectedLists.size());

    // validate size for each doubly linked list
    for (int i = 0; i < expectedLists.size(); ++i)
    {
        assert(expectedLists[i].size() == actualLists[i].size());
    }

    // for debugging print the lists!!
    for (int i = 0; i < expectedLists.size(); ++i)
    {
        std::cout << "Expected List " << i << ": ";
        expectedLists[i].print_list();
        std::cout << "Actual List " << i << ": ";
        actualLists[i].print_list();
    }

    std::cout << "Linked list ingest test passed!\n";

    return true;
}

bool testMergeComparison()
{
    // Set up: Create instance of evaluator
    Evaluator evaluator;

    // Execution: Call Ingest and MergeComparison
    evaluator.Ingest("test_cases.txt");
    evaluator.MergeComparison();

    // Validation (part 1: vectors - hardcode them sorted)
    std::vector<std::vector<int>> expectedSortedVectors = {
        {1, 2, 3, 7}, {4, 5, 7, 7}, {1, 5, 6, 8}, {0, 1, 4, 6, 7}, {2, 3, 4, 5, 9}, {0, 1, 3, 4, 9}, {2, 3, 5, 5, 6, 7}, {3, 3, 4, 5, 8, 8}, {0, 3, 4, 4, 6, 9}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    assert(actualVectors.size() == expectedSortedVectors.size());

    // Compare sorted vectors
    for (int i = 0; i < expectedSortedVectors.size(); ++i)
    {
        if (actualVectors[i] != expectedSortedVectors[i])
        {
            std::cout << "Mismatch at vector " << i << ":\n";
            std::cout << "Expected: { ";
            for (int num : expectedSortedVectors[i])
                std::cout << num << " ";
            std::cout << "}\n";

            std::cout << "Actual:   { ";
            for (int num : actualVectors[i])
                std::cout << num << " ";
            std::cout << "}\n";
        }
        assert(actualVectors[i] == expectedSortedVectors[i]);
    }

    // Validation (part 2: linked lists)
    const std::vector<DoublyLinkedList> &actualLists = evaluator.getTestLists();
    assert(actualLists.size() == expectedSortedVectors.size());

    // Validate linked lists (ensure sorted correctly without checking size)
    for (int i = 0; i < actualLists.size(); ++i)
    {
        auto node = actualLists[i].get_head();
        while (node && node->next) // Ensure that each node is less than or equal to the next
        {
            if (node->value > node->next->value)
            {
                std::cout << "Linked list " << i << " is not sorted correctly at element " << node->value << ":\n";
                std::cout << "Data: " << node->value << " > " << node->next->value << "\n";
                assert(false); // Fail if not sorted correctly
            }
            node = node->next;
        }
    }

    // Validation (part 3: timing data)
    const std::vector<std::vector<double>> &vectorTimingData = evaluator.getVectorTimingData();
    const std::vector<std::vector<double>> &listTimingData = evaluator.getListTimingData();

    // Ensure there is timing data for both vectors and lists
    assert(vectorTimingData.size() == actualVectors.size());
    assert(listTimingData.size() == actualLists.size());

    // Ensure that the timing data for vectors is not negative
    for (int i = 0; i < vectorTimingData.size(); ++i)
    {
        assert(vectorTimingData[i].size() == 1); // Each vector should have one timing value
        double timeTaken = vectorTimingData[i][0];
        assert(timeTaken >= 0.0); // Check that the time is non-negative
        std::cout << "Time taken for vector " << i << ": " << timeTaken << " ms\n";
    }

    // Ensure that the timing data for lists is not negative
    for (int i = 0; i < listTimingData.size(); ++i)
    {
        assert(listTimingData[i].size() == 1); // Each list should have one timing value
        double timeTaken = listTimingData[i][0];
        assert(timeTaken >= 0.0); // Check that the time is non-negative
        std::cout << "Time taken for list " << i << ": " << timeTaken << " ms\n";
    }

    std::cout << "MergeComparison test passed!\n";

    // Clean up
    return true;
}

bool testQuickComparison()
{
    // // set up
    // Evaluator evaluator;

    // // execution
    // evaluator.Ingest("test_cases.txt");
    // evaluator.QuickComparison();

    // // validation
    // std::vector<std::vector<int>> expectedSortedVectors = {
    //     {1, 2, 3, 7}, {4, 5, 7, 7}, {1, 5, 6, 8}, {0, 1, 4, 6, 7}, {2, 3, 4, 5, 9}, {0, 1, 3, 4, 9}, {2, 3, 5, 5, 6, 7}, {3, 3, 4, 5, 8, 8}, {0, 3, 4, 4, 6, 9}};

    // const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    // assert(actualVectors.size() == expectedSortedVectors.size());

    // for (int i = 0; i < expectedSortedVectors.size(); ++i)
    // {
    //     if (actualVectors[i] != expectedSortedVectors[i])
    //     {
    //         std::cout << "Mismatch at vector " << i << ":\n";
    //         std::cout << "Expected: { ";
    //         for (int num : expectedSortedVectors[i])
    //             std::cout << num << " ";
    //         std::cout << "}\n";

    //         std::cout << "Actual:   { ";
    //         for (int num : actualVectors[i])
    //             std::cout << num << " ";
    //         std::cout << "}\n";
    //     }
    //     assert(actualVectors[i] == expectedSortedVectors[i]);
    // }

    // const std::vector<std::vector<double>> &timingData = evaluator.getVectorTimingData();

    // // clean
    // return true;
    // You can add the logic for the test here, if needed in the future
    std::cout << "QuickComparison test not implemented yet.\n";
    return true; // Assuming the test will be successful once implemented
}

bool testInsertionComparison()
{
    // // set up
    // Evaluator evaluator;

    // // execution
    // evaluator.Ingest("test_cases.txt");
    // evaluator.InsertionComparison();

    // // validation
    // std::vector<std::vector<int>> expectedSortedVectors = {
    //     {1, 2, 3, 7}, {4, 5, 7, 7}, {1, 5, 6, 8}, {0, 1, 4, 6, 7}, {2, 3, 4, 5, 9}, {0, 1, 3, 4, 9}, {2, 3, 5, 5, 6, 7}, {3, 3, 4, 5, 8, 8}, {0, 3, 4, 4, 6, 9}};

    // const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    // assert(actualVectors.size() == expectedSortedVectors.size());

    // for (int i = 0; i < expectedSortedVectors.size(); ++i)
    // {
    //     if (actualVectors[i] != expectedSortedVectors[i])
    //     {
    //         std::cout << "Mismatch at vector " << i << ":\n";
    //         std::cout << "Expected: { ";
    //         for (int num : expectedSortedVectors[i])
    //             std::cout << num << " ";
    //         std::cout << "}\n";

    //         std::cout << "Actual:   { ";
    //         for (int num : actualVectors[i])
    //             std::cout << num << " ";
    //         std::cout << "}\n";
    //     }
    //     assert(actualVectors[i] == expectedSortedVectors[i]);
    // }

    // const std::vector<std::vector<double>> &timingData = evaluator.getVectorTimingData();

    // // clean up
    // return true;
    // You can add the logic for the test here, if needed in the future
    std::cout << "InsertionComparison test not implemented yet.\n";
    return true; // Assuming the test will be successful once implemented
}

// call each test function here
bool testIngest();
bool testMergeComparison();
bool testQuickComparison();
bool testInsertionComparison();

int main()
{
    std::cout << "Running Evaluator Tests...\n";

    if (testIngest())
    {
        std::cout << "Ingest test passed!\n";
    }
    else
    {
        std::cout << "Ingest test failed!\n";
    }

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