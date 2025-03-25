#include "evaluator.hpp"
#include <iostream>
#include <cassert>

bool testIngest()
{
    // NOTE: just going to write for vectors right now

    // set up (create an instance of Evaluator class)
    Evaluator evaluator;

    // execution (calling the Ingest function)
    evaluator.Ingest("test_cases.txt");

    // validation
    std::vector<std::vector<int>> expectedVectors = {
        {1, 2, 7, 3}, {4, 5, 7, 7}, {1, 5, 8, 6}, {6, 1, 4, 0, 7}, {5, 3, 2, 4, 9}, {4, 1, 3, 0, 9}, {7, 3, 6, 5, 2, 5}, {8, 3, 5, 4, 8, 3}, {3, 0, 6, 4, 4, 9}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();

    assert(actualVectors.size() == expectedVectors.size());

    for (int i = 0; i < expectedVectors.size(); ++i)
    {
        assert(actualVectors[i] == expectedVectors[i]);
    }

    std::cout << "Vector ingest test passed!\n";


    //for doublylinked list!!!!: 
    Evaluator evaluatorDLL;

    //same data
    std::vector<std::vector<int>> expectedData = {
        {1, 2, 7, 3}, {4, 5, 7, 7}, {1, 5, 8, 6}, {6, 1, 4, 0, 7}, {5, 3, 2, 4, 9}, {4, 1, 3, 0, 9}, {7, 3, 6, 5, 2, 5}, {8, 3, 5, 4, 8, 3}, {3, 0, 6, 4, 4, 9}};

    DoublyLinkedList &actuallistDLL = evaluatorDLL.getTestList();
    //std::cout << "past first" << std::endl;
    //std::cout << actuallistDLL.get_head() << std::endl;
    //std::cout << "past second" << std::endl;
    DLLNode *currentNode = actuallistDLL.get_head();
    int counter = 0;

    //std::cout << expectedData.size() << std::endl;
    
    //currentNode is currently being seen as nullptr!! That is an issue I am dealing with
    //not entering the while statement
    while(currentNode && counter < expectedData.size())
    {
        std::vector<int> actualDigits;
        DLLNode *digitNode = currentNode->next;

        while(digitNode != nullptr)
        {
            actualDigits.push_back(digitNode->value);
            digitNode = digitNode->next;
        }

        assert(actualDigits == expectedData[counter]);
        std::cout << "past this assertion statement" << std::endl;
        currentNode = currentNode->next;
        counter ++;
        //std::cout << counter << std::endl;
    }
    //std:: cout << counter<< std::endl;
    assert(counter == expectedData.size());
    std::cout << "Doubly linked list ingest test passed!\n";

    // clean up
    return true;
}

bool testMergeComparison()
{
    // set up
    Evaluator evaluator;

    // execution
    evaluator.Ingest("test_cases.txt");
    evaluator.MergeComparison();

    // validation
    std::vector<std::vector<int>> expectedSortedVectors = {
        {1, 2, 3, 7}, {4, 5, 7, 7}, {1, 5, 6, 8}, {0, 1, 4, 6, 7}, {2, 3, 4, 5, 9}, {0, 1, 3, 4, 9}, {2, 3, 5, 5, 6, 7}, {3, 3, 4, 5, 8, 8}, {0, 3, 4, 4, 6, 9}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    assert(actualVectors.size() == expectedSortedVectors.size());

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

    const std::vector<std::vector<double>> &timingData = evaluator.getTimingData();

    // this makes sure that we have a timing measurement for each vector
    assert(timingData.size() == actualVectors.size());

    for (int i = 0; i < timingData.size(); ++i)
    {
        // check that each vector should have exactly one timing value
        assert(timingData[i].size() == 1);

        double timeTaken = timingData[i][0]; // grabs the timing value for this vector sort
        assert(timeTaken >= 0.0);            // check that the time is non negative

        std::cout << "Time taken for vector " << i << ": " << timeTaken << " ms\n";
    }

    std::cout << "MergeComparison test passed!\n";

    // clean up
    return true;
}

bool testQuickComparison()
{
    // set up
    Evaluator evaluator;

    // execution
    evaluator.Ingest("test_cases.txt");
    evaluator.QuickComparison();

    // validation
    std::vector<std::vector<int>> expectedSortedVectors = {
        {1, 2, 3, 7}, {4, 5, 7, 7}, {1, 5, 6, 8}, {0, 1, 4, 6, 7}, {2, 3, 4, 5, 9}, {0, 1, 3, 4, 9}, {2, 3, 5, 5, 6, 7}, {3, 3, 4, 5, 8, 8}, {0, 3, 4, 4, 6, 9}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    assert(actualVectors.size() == expectedSortedVectors.size());

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

    const std::vector<std::vector<double>> &timingData = evaluator.getTimingData();

    // clean 
    return true;
}

bool testInsertionComparison()
{
    // set up
    Evaluator evaluator;

    // execution
    evaluator.Ingest("test_cases.txt");
    evaluator.InsertionComparison();

    // validation
    std::vector<std::vector<int>> expectedSortedVectors = {
        {1, 2, 3, 7}, {4, 5, 7, 7}, {1, 5, 6, 8}, {0, 1, 4, 6, 7}, {2, 3, 4, 5, 9}, {0, 1, 3, 4, 9}, {2, 3, 5, 5, 6, 7}, {3, 3, 4, 5, 8, 8}, {0, 3, 4, 4, 6, 9}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    assert(actualVectors.size() == expectedSortedVectors.size());

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

    const std::vector<std::vector<double>> &timingData = evaluator.getTimingData();

    // clean up
    return true;
}

void testEvaluate()
{
    // set up


    // execution


    // validation


    // clean up
}