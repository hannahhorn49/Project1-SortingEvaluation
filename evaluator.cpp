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
        ++lineCount;
        std::stringstream ss(line);
        int number;

        std::cout << "Line " << lineCount << ": " << line << "\n";

        // parse numbers in the line
        while (ss >> number)
        {
            std::vector<int> digitVector;

            std::string numStr = std::to_string(number);
            for (char c : numStr)
            {
                digitVector.push_back(c - '0');
            }

            testVectors.push_back(digitVector);

            // concise debug print
            std::cout << "  Added number: " << number << " as vector: { ";
            for (int digit : digitVector)
                std::cout << digit << " ";
            std::cout << "}\n";
        }
    }

    inputFile.close();

    std::cout << "--- Ingest Completed. Total vectors: " << testVectors.size() << " ---\n\n";
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