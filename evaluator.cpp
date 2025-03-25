#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>

void Evaluator::Ingest(const std::string &filePath)
{
    std::ifstream inputFile(filePath); // open file
    if (!inputFile.is_open())
    {
        std::cout << "Error: Could not open file: " << filePath << std::endl; // check if file is opened
        return;
    }

    std::string line;
    int lineCount = 0;

    // loop through each line of file
    while (std::getline(inputFile, line))
    {
        ++lineCount;
        std::stringstream ss(line);
        int number = 0;

        std::cout << "Line " << lineCount << ": " << line << "\n";

        while (ss >> number)
        {
            // initialize for linked list
            DoublyLinkedList digitList;

            // initialize for vector
            std::vector<int> digitVector;

            // go from number -> string in order to separate the digits
            std::string numStr = std::to_string(number);

            // fill the vector AND linked list with the individual digits
            for (char c : numStr)
            {
                int digit = c - '0';
                digitVector.push_back(digit);
                digitList.push_back(digit);
            }

            // store the digit vector in the testVectors container
            testVectors.push_back(digitVector);

            // store the digit linked list in the testLists container
            testLists.push_back(digitList);

            // debug print here
            std::cout << "  Added number: " << number << " as vector: { ";
            for (int digit : digitVector)
                std::cout << digit << " ";
            std::cout << "} and as linked list: ";
            digitList.print_list();
        }
    }

    inputFile.close();

    // final print to show final count of vectors and linked lists
    std::cout << "--- Ingest Completed. Total vectors: " << testVectors.size()
              << ", Total linked lists: " << testLists.size() << " ---\n\n";
}

void Evaluator::MergeComparison()
{
    std::cout << "\n--- Starting MergeComparison ---\n";

    // loop through each test case
    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        // get the reference to the vector in testVectors
        auto &vec = testVectors[i];

        // create a copy of the vector to so don't modify original data
        std::vector<int> vecCopy = vec;

        // for debugging print!!!
        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // start timer
        auto start = std::chrono::high_resolution_clock::now();

        // sort copy
        VectorSorter::merge_sort(vecCopy);

        // end timer
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        double timeTakenForVector = duration.count();

        // store time for vector sort
        vectorTimingData.push_back({timeTakenForVector});
        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << timeTakenForVector << " ms\n";

        // update original vector
        testVectors[i] = vecCopy;

        // same process here for doubly linked list
        // create doubly linked list and populate with vec values
        DoublyLinkedList list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // for debugging print original list!!
        std::cout << "Original linked list " << i << ": ";
        list.print_list();
        std::cout << "\n";

        // start timer
        auto listStart = std::chrono::high_resolution_clock::now();

        // sort
        list.DLL_merge_sort(list.get_head());

        // end timer
        auto listEnd = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> listDuration = listEnd - listStart;
        double timeTakenForList = listDuration.count();

        // store data
        listTimingData.push_back({timeTakenForList});
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << timeTakenForList << " ms\n";
    }

    std::cout << "--- MergeComparison Completed ---\n\n";
}

void Evaluator::InsertionComparison()
{
    // std::cout << "\n--- Starting InsertionComparison ---\n";

    // for (size_t i = 0; i < testVectors.size(); ++i)
    // {
    //     auto &vec = testVectors[i]; // get a reference to the vector in testVectors

    //     std::vector<int> vecCopy = vec; // copy the vector to preserve original data

    //     std::cout << "Original vector " << i << ": { ";
    //     for (int num : vec)
    //         std::cout << num << " ";
    //     std::cout << "}\n";

    //     // timer start
    //     auto start = std::chrono::high_resolution_clock::now();

    //     VectorSorter::insertion_sort(vecCopy); // sort the copy by calling function

    //     // timer end
    //     auto end = std::chrono::high_resolution_clock::now();
    //     std::chrono::duration<double, std::milli> duration = end - start;
    //     double timeTaken = duration.count();

    //     timingData.push_back({timeTaken}); // we store the time taken for this sort

    //     std::cout << "Sorted vector " << i << ": { ";
    //     for (int num : vecCopy)
    //         std::cout << num << " ";
    //     std::cout << "} Time: " << timeTaken << " ms\n";

    //     testVectors[i] = vecCopy; // this updates the original vector in testVectors with the sorted one
    // }

    // std::cout << "--- InsertionComparison Completed ---\n\n";
}

void Evaluator::QuickComparison()
{
    // std::cout << "\n--- Starting QuickComparison ---\n";

    // for (size_t i = 0; i < testVectors.size(); ++i)
    // {
    //     auto &vec = testVectors[i]; // get a reference to the vector in testVectors

    //     std::vector<int> vecCopy = vec; // copy the vector to preserve original data

    //     std::cout << "Original vector " << i << ": { ";
    //     for (int num : vec)
    //         std::cout << num << " ";
    //     std::cout << "}\n";

    //     // timer start
    //     auto start = std::chrono::high_resolution_clock::now();

    //     VectorSorter::quick_sort(vecCopy); // sort the copy by calling function

    //     // timer end
    //     auto end = std::chrono::high_resolution_clock::now();
    //     std::chrono::duration<double, std::milli> duration = end - start;
    //     double timeTaken = duration.count();

    //     timingData.push_back({timeTaken}); // we store the time taken for this sort

    //     std::cout << "Sorted vector " << i << ": { ";
    //     for (int num : vecCopy)
    //         std::cout << num << " ";
    //     std::cout << "} Time: " << timeTaken << " ms\n";

    //     testVectors[i] = vecCopy; // this updates the original vector in testVectors with the sorted one
    // }

    // std::cout << "--- QuickComparison Completed ---\n\n";
}