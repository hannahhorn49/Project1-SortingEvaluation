#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>

void Evaluator::Ingest(const std::string &filePath)
{
    std::cout << "\n--- Starting Ingest Function ---\n";

    std::ifstream inputFile(filePath); // open file
    if (!inputFile.is_open())          // check file
    {
        std::cout << "Error: Could not open file: " << filePath << std::endl;
        return;
    }

    std::string line;
    int lineCount = 0;

    while (std::getline(inputFile, line))
    {
        //std::cout << "going into while statement" << std::endl;
        ++lineCount;
        std::stringstream ss(line);
        int number = 0;

        std::cout << "Line " << lineCount << ": " << line << "\n";

        // parse numbers in the line
        while (ss >> number)
        {
            //OFFICE HOURS: 
            //for doubly linked lists: - we are creating a linked list of linked lists? OR should we create a vector of linked lists 
            DoublyLinkedList digitList;

            //for vector
            std::vector<int> digitVector;

            std::string numStr = std::to_string(number);
            for (char c : numStr)
            {
                //filling the doubly linked list
                digitList.push_back(c - '0');

                //filling the vector
                digitVector.push_back(c - '0');
            }

            //cannot push_back another list, so doing this: 

            testLists.push_back(-1); //this is used as a placeholder: to tell where an ending of a list goes. used for debugging 
            //first number would be negative one
            //MAY NEED TO CHANGE THIS: 
            digitList.update_head_tail(testLists.get_tail()); //updates the list and pushes back
            //if we do vector of linked lists: it would be easier

            //for vectors: 
            testVectors.push_back(digitVector);

            // concise debug print
            std::cout << "  Added number: " << number << " as vector: { ";
            for (int digit : digitVector)
                std::cout << digit << " ";
            std::cout << "}\n";


        }
    }

    inputFile.close();

    /*USE FOR FINDING LINKED LISTS: 
    int counter = 0;
    DLLNode *current = digitList.get_head();
    while (current != nullptr)
    {
        if (current->value == -1)
        {
            counter ++;
        }
        current = current->next;
    }*/

    std::cout << "--- Ingest Completed. Total vectors: " << testVectors.size() << "---\n\n"; // << "---- Total linked lists: " << counter
}

void Evaluator::MergeComparison()
{
    std::cout << "\n--- Starting MergeComparison ---\n";

    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        auto &vec = testVectors[i]; // get a reference to the vector in testVectors

        std::vector<int> vecCopy = vec; // copy the vector to preserve original data

        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // timer start
        auto start = std::chrono::high_resolution_clock::now();

        VectorSorter::merge_sort(vecCopy); // sort the copy by calling function

        // timer end
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        double timeTaken = duration.count();

        timingData.push_back({timeTaken}); // we store the time taken for this sort

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << timeTaken << " ms\n";

        testVectors[i] = vecCopy; // this updates the original vector in testVectors with the sorted one
    }

    std::cout << "--- MergeComparison Completed ---\n\n";
}

void Evaluator::InsertionComparison()
{
    std::cout << "\n--- Starting InsertionComparison ---\n";

    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        auto &vec = testVectors[i]; // get a reference to the vector in testVectors

        std::vector<int> vecCopy = vec; // copy the vector to preserve original data

        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // timer start
        auto start = std::chrono::high_resolution_clock::now();

        VectorSorter::insertion_sort(vecCopy); // sort the copy by calling function

        // timer end
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        double timeTaken = duration.count();

        timingData.push_back({timeTaken}); // we store the time taken for this sort

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << timeTaken << " ms\n";

        testVectors[i] = vecCopy; // this updates the original vector in testVectors with the sorted one
    }

    std::cout << "--- InsertionComparison Completed ---\n\n";
}

void Evaluator::QuickComparison()
{
    std::cout << "\n--- Starting QuickComparison ---\n";

    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        auto &vec = testVectors[i]; // get a reference to the vector in testVectors

        std::vector<int> vecCopy = vec; // copy the vector to preserve original data

        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // timer start
        auto start = std::chrono::high_resolution_clock::now();

        VectorSorter::quick_sort(vecCopy); // sort the copy by calling function

        // timer end
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
        double timeTaken = duration.count();

        timingData.push_back({timeTaken}); // we store the time taken for this sort

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << timeTaken << " ms\n";

        testVectors[i] = vecCopy; // this updates the original vector in testVectors with the sorted one
    }

    std::cout << "--- QuickComparison Completed ---\n\n";
}