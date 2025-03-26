#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip> // for table formatting

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

    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = testVectors[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData.back()[0] << " ms\n";

        testVectors[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        DoublyLinkedList originalList = list;

        // debuggin!
        std::cout << "Original linked list " << i << ": ";
        originalList.print_list();
        std::cout << "\n";

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_merge_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData.back()[0] << " ms\n";

        testLists[i] = list;
    }

    std::cout << "--- MergeComparison Completed ---\n\n";
}

void Evaluator::InsertionComparison()
{
    std::cout << "\n--- Starting InsertionComparison ---\n";

    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = testVectors[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData.back()[0] << " ms\n";

        testVectors[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        DoublyLinkedList originalList = list;

        // debuggin!
        std::cout << "Original linked list " << i << ": ";
        originalList.print_list();
        std::cout << "\n";

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_insertion_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData.back()[0] << " ms\n";

        testLists[i] = list;
    }

    std::cout << "--- InsertionComparison Completed ---\n\n";
}

void Evaluator::QuickComparison()
{
    std::cout << "\n--- Starting QuickComparison ---\n";

    for (size_t i = 0; i < testVectors.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = testVectors[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        std::cout << "Original vector " << i << ": { ";
        for (int num : vec)
            std::cout << num << " ";
        std::cout << "}\n";

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::quick_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData.back()[0] << " ms\n";

        testVectors[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        DoublyLinkedList originalList = list;

        // debuggin!
        std::cout << "Original linked list " << i << ": ";
        originalList.print_list();
        std::cout << "\n";

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_quick_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData.back()[0] << " ms\n";

        testLists[i] = list;
    }

    std::cout << "--- QuickComparison Completed ---\n\n";
}

void Evaluator::Evaluate()
{
    Evaluator test;
    test.Ingest("evaluation_cases.txt");
    test.MergeComparison();
    test.InsertionComparison();
    test.QuickComparison();

    const std::vector<std::vector<int>> &testVectors = test.getTestVectors();
    const std::vector<std::vector<double>> &vectorTimingData = test.getVectorTimingData();
    const std::vector<std::vector<double>> &listTimingData = test.getListTimingData();

    // open the file in order to save output in separate file (so not just in console)
    std::ofstream outputFile("comparison_results.txt");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return;
    }

    // write headers to both the console and file
    std::cout << "-------------------------------------Time of Comparisons-------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "||------- SORTED LIST ------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- || --------- Sort Used -------- ||" << std::endl;

    outputFile << "-------------------------------------Time of Comparisons-------------------------------------" << std::endl;
    outputFile << "---------------------------------------------------------------------------------------------" << std::endl;
    outputFile << "||------- SORTED LIST ------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- || --------- Sort Used -------- ||" << std::endl;

    for (int i = 0; i < testVectors.size(); i++)
    {
        std::string print_number = "";
        for (int j = 0; j < testVectors[i].size(); j++)
        {
            print_number += std::to_string(testVectors[i][j]);
        }

        auto write_result = [&](double time, const std::string &container_type, const std::string &sort_type)
        {
            std::ostringstream line;
            line << "|--------|---" << print_number << " ---| ------ | -------- "
                 << std::fixed << std::setprecision(6) << time
                 << " --------|------------- " << container_type << " -------------|------------- " << sort_type << " -----------|";
            std::cout << line.str() << std::endl;
            outputFile << line.str() << std::endl;
        };

        // MERGE sort results
        write_result(listTimingData[i][0], "Linked List", "MERGE");
        write_result(vectorTimingData[i][0], "Vector", "MERGE");

        // INSERTION sort results
        write_result(listTimingData[i + 9][0], "Linked List", "INSERTION");
        write_result(vectorTimingData[i + 9][0], "Vector", "INSERTION");

        // QUICK sort results
        write_result(listTimingData[i + 18][0], "Linked List", "QUICK");
        write_result(vectorTimingData[i + 18][0], "Vector", "QUICK");

        std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        outputFile << "-----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }

    // close the file after writing
    outputFile.close();
    std::cout << "Comparison results saved to 'comparison_results.txt'!" << std::endl;
}
