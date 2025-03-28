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

    // THIS NOW WORKS (I believe)
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

        std::vector<int> currentLineNumbers;
        DoublyLinkedList currentList;
        // print(line)
        ++lineCount;
        std::stringstream ss(line);
        std::string number;

        std::cout << "Line " << lineCount << ": " << line << "\n";

        // Read all numbers in this line
        while (std::getline(ss, number, ' '))
        {
            int transformed = std::stoi(number);
            currentLineNumbers.push_back(transformed);
            currentList.push_back(transformed);
        }
        if (currentLineNumbers.size() == 100)
        {
            Vector100.push_back(currentLineNumbers);
            List100.push_back(currentList);
        }
        else if (currentLineNumbers.size() == 1000)
        {
            Vector1000.push_back(currentLineNumbers);
            List1000.push_back(currentList);
        }
        else if (currentLineNumbers.size() == 10000)
        {
            Vector10000.push_back(currentLineNumbers);
            List10000.push_back(currentList);
        }
    }
    // std::cout << getTestVectors1000().size() << std::endl;
    // std::cout << List1000.size() << std::endl;
}

void Evaluator::InsertionComparison()
{
    std::cout << "\n--- Starting InsertionComparison ---\n";

    // LOOP 1
    for (size_t i = 0; i < Vector100.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector100[i];
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
        vectorTimingData100.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData100.back() << " ms\n";

        Vector100[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List100[i];
        DoublyLinkedList originalList = list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        std::cout << "Original linked list (100)" << i << ": ";
        originalList.print_list();
        std::cout << "\n";

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_insertion_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData100.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData100.back() << " ms\n";

        List100[i] = list;
    }

    // LOOP 2
    for (size_t i = 0; i < Vector1000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
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
        vectorTimingData1000.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData1000.back() << " ms\n";

        Vector1000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List1000[i];
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
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData1000.back() << " ms\n";

        List1000[i] = list;
    }

    // LOOP 3
    for (size_t i = 0; i < Vector10000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector10000[i];
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
        vectorTimingData10000.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData10000.back() << " ms\n";

        Vector10000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List10000[i];
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
        listTimingData10000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData10000.back() << " ms\n";

        List10000[i] = list;
    }

    std::cout << "--- MergeComparison Completed ---\n\n";
}

void Evaluator::QuickComparison()
{
    std::cout << "\n--- Starting QuickComparison ---\n";

    // LOOP 1
    for (size_t i = 0; i < Vector100.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector100[i];
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
        vectorTimingData100.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData100.back() << " ms\n";

        Vector100[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List100[i];
        DoublyLinkedList originalList = list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        std::cout << "Original linked list (100)" << i << ": ";
        originalList.print_list();
        std::cout << "\n";

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_quick_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData100.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData100.back() << " ms\n";

        List100[i] = list;
    }

    // LOOP 2
    for (size_t i = 0; i < Vector1000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
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
        vectorTimingData1000.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData1000.back() << " ms\n";

        Vector1000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List100[i];
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
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData1000.back() << " ms\n";

        List1000[i] = list;
    }

    // LOOP 3
    for (size_t i = 0; i < Vector10000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
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
        vectorTimingData10000.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData10000.back() << " ms\n";

        Vector10000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List10000[i];
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
        listTimingData10000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData10000.back() << " ms\n";

        List10000[i] = list;
    }

    std::cout << "--- QuickComparison Completed ---\n\n";
}

void Evaluator::MergeComparison()
{
    std::cout << "\n--- Starting MergeComparison ---\n";

    // LOOP 1
    for (size_t i = 0; i < Vector100.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector100[i];
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
        vectorTimingData100.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData100.back() << " ms\n";

        Vector100[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List100[i];
        DoublyLinkedList originalList = list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        std::cout << "Original linked list (100)" << i << ": ";
        originalList.print_list();
        std::cout << "\n";

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_merge_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData100.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData100.back() << " ms\n";

        List100[i] = list;
    }

    // LOOP 2
    for (size_t i = 0; i < Vector1000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
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
        vectorTimingData1000.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData1000.back() << " ms\n";

        Vector1000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List100[i];
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
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData1000.back() << " ms\n";

        List1000[i] = list;
    }

    // LOOP 3
    for (size_t i = 0; i < Vector10000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
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
        vectorTimingData10000.push_back({std::chrono::duration<double, std::milli>(end - start).count()});

        std::cout << "Sorted vector " << i << ": { ";
        for (int num : vecCopy)
            std::cout << num << " ";
        std::cout << "} Time: " << vectorTimingData10000.back() << " ms\n";

        Vector10000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List10000[i];
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
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        std::cout << "Sorted linked list " << i << ": ";
        list.print_list();
        std::cout << "} Time: " << listTimingData10000.back() << " ms\n";

        List10000[i] = list;
    }

    std::cout << "--- MergeComparison Completed ---\n\n";
}

// void Evaluator::Evaluate()
// {
//     Evaluator test;
//     const std::vector<std::vector<int>> &Vector100 = test.getTestVectors100();
//     const std::vector<std::vector<int>> &Vector1000 = test.getTestVectors1000();
//     const std::vector<std::vector<int>> &Vector10000 = test.getTestVectors10000();

//     const std::vector<std::vector<int>> &List100 = test.getTestLists100();
//     const std::vector<std::vector<int>> &List1000 = test.getTestLists1000();
//     const std::vector<std::vector<int>> &List10000 = test.getTestLists10000();

//     const std::vector<std::vector<int>> &vectorTimingData100 = test.VectorTimingData100();
//     const std::vector<std::vector<int>> &vectorTimingData1000 = test.VectorTimingData1000();
//     const std::vector<std::vector<int>> &vectorTimingData10000 = test.VectorTimingData10000();

//     const std::vector<std::vector<int>> &listTimingData100 = test.ListTimingData100();
//     const std::vector<std::vector<int>> &listTimingData1000 = test.ListTimingData1000();
//     const std::vector<std::vector<int>> &listTimingData10000 = test.ListTimingData10000();
//     test.Ingest("evaluation_cases.txt");
//     test.MergeComparison();
//     test.InsertionComparison();
//     test.QuickComparison();
// }

//     // open the file in order to save output in separate file (so not just in console)
//     std::ofstream outputFile("comparison_results.txt");
//     if (!outputFile.is_open())
//     {
//         std::cerr << "Error: Unable to open file for writing!" << std::endl;
//         return;
//     }

//     // write headers to both the console and file
//     std::cout << "-------------------------------------Time of Comparisons-------------------------------------" << std::endl;
//     std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
//     std::cout << "||------- SORTED LIST ------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- || --------- Sort Used -------- ||" << std::endl;

//     outputFile << "-------------------------------------Time of Comparisons-------------------------------------" << std::endl;
//     outputFile << "---------------------------------------------------------------------------------------------" << std::endl;
//     outputFile << "||------- SORTED LIST ------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- || --------- Sort Used -------- ||" << std::endl;

//     for (int i = 0; i < testVectors.size(); i++)
//     {
//         std::string print_number = "";
//         for (int j = 0; j < testVectors[i].size(); j++)
//         {
//             print_number += std::to_string(testVectors[i][j]);
//         }

//         auto write_result = [&](double time, const std::string &container_type, const std::string &sort_type)
//         {
//             std::ostringstream line;
//             line << "|--------|---" << print_number << " ---| ------ | -------- "
//                  << std::fixed << std::setprecision(6) << time
//                  << " --------|------------- " << container_type << " -------------|------------- " << sort_type << " -----------|";
//             std::cout << line.str() << std::endl;
//             outputFile << line.str() << std::endl;
//         };

//         // MERGE sort results
//         write_result(listTimingData[i][0], "Linked List", "MERGE");
//         write_result(vectorTimingData[i][0], "Vector", "MERGE");

//         // INSERTION sort results
//         write_result(listTimingData[i + 9][0], "Linked List", "INSERTION");
//         write_result(vectorTimingData[i + 9][0], "Vector", "INSERTION");

//         // QUICK sort results
//         write_result(listTimingData[i + 18][0], "Linked List", "QUICK");
//         write_result(vectorTimingData[i + 18][0], "Vector", "QUICK");

//         std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
//         outputFile << "-----------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
//     }

//     // close the file after writing
//     outputFile.close();
//     std::cout << "Comparison results saved to 'comparison_results.txt'!" << std::endl;
// }
// void Evaluator::Evaluate()
// {
//     MergeComparison();
//     InsertionComparison();
//     QuickComparison();

// const std::vector<std::vector<int>> &getTestVectors100() const { return Vector100; }
// const std::vector<std::vector<int>> &getTestVectors1000() const { return Vector1000; }
// const std::vector<std::vector<int>> &getTestVectors10000() const { return Vector10000; }

// const std::vector<DoublyLinkedList> &getTestLists100() const { return List100; }
// const std::vector<DoublyLinkedList> &getTestLists1000() const { return List1000; }
// const std::vector<DoublyLinkedList> &getTestLists10000() const { return List10000; }

// const std::vector<std::vector<double>> &getVectorTimingData100() const { return vectorTimingData100; }
// const std::vector<std::vector<double>> &getListTimingData100() const { return listTimingData100; }

// const std::vector<std::vector<double>> &getVectorTimingData1000() const { return vectorTimingData1000; }
// const std::vector<std::vector<double>> &getListTimingData1000() const { return listTimingData1000; }

// const std::vector<std::vector<double>> &getVectorTimingData10000() const { return vectorTimingData10000; }
// const std::vector<std::vector<double>> &getListTimingData10000() const { return listTimingData10000; }

//     // open the CSV file for output (use a unique file name for each run, e.g., "run1.csv")
//     std::ofstream outputFile("run10.csv");
//     if (!outputFile.is_open())
//     {
//         std::cerr << "Error: Unable to open file for writing!" << std::endl;
//         return;
//     }

//     // write the CSV headers
//     outputFile << "Case,Data Structure,Sort Type,Time (Seconds)" << std::endl;

//     for (int i = 0; i < testVectors.size(); i++)
//     {
//         std::string case_number = "";
//         for (int j = 0; j < testVectors[i].size(); j++)
//         {
//             case_number += std::to_string(testVectors[i][j]);
//         }

//         // write each result to the CSV file
//         auto write_result = [&](double time, const std::string &container_type, const std::string &sort_type)
//         {
//             outputFile << case_number << "," << container_type << "," << sort_type << "," << std::fixed << std::setprecision(6) << time << std::endl;
//         };

//         // MERGE sort results
//         write_result(listTimingData[i][0], "Linked List", "MERGE");
//         write_result(vectorTimingData[i][0], "Vector", "MERGE");

//         // INSERTION sort results
//         write_result(listTimingData[i + 9][0], "Linked List", "INSERTION");
//         write_result(vectorTimingData[i + 9][0], "Vector", "INSERTION");

//         // QUICK sort results
//         write_result(listTimingData[i + 18][0], "Linked List", "QUICK");
//         write_result(vectorTimingData[i + 18][0], "Vector", "QUICK");
//     }

//     // close the file after writing
//     outputFile.close();
//     std::cout << "Comparison results saved to 'run10.csv'!" << std::endl;
// }
