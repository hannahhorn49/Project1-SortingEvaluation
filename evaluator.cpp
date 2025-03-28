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

    // Vectors to hold different sizes of data
    std::vector<int> Vector100[4];
    std::vector<int> currentLineNumbers;

    // std::vector<std::vector<int>> Vector100; // 4 vectors of size 100
    // std::vector<std::vector<int>> Vector1000; // 4 vectors of size 1000
    // std::vector<std::vector<int>> Vector10000; // 4 vectors of size 10000

    // std::vector<DoublyLinkedList*> List100; // 4 vectors of DoublyLinkedList for size 100
    // std::vector<DoublyLinkedList*> List1000; // 4 vectors of DoublyLinkedList for size 1000
    // std::vector<DoublyLinkedList*> List10000; // 4 vectors of DoublyLinkedList for size 10000


    // loop through each line of file
    while (std::getline(inputFile, line))
    {
        ++lineCount;
        std::stringstream ss(line);
        int number = 0;

        std::cout << "Line " << lineCount << ": " << line << "\n";

        
        // Temporary containers for current line's vector and linked list
        //std::vector<int> currentVector;
        //DoublyLinkedList* currentList;

        // Read all numbers in this line
        while (ss >> number)
        {
            //currentLineNumbers.push_back(number);
            // Convert number to string to extract digits
            std::string numStr = std::to_string(number);

            //Fill the vector and linked list with digits
            for (char c : numStr)
            {
                int digit = c - '0';  // Convert char to integer
                currentLineNumbers.push_back(digit);
                //currentVector.push_back(digit);
                //currentList.push_back(digit);
            }
        }

        // Determine the size of the current data
        //size_t dataSize = currentVector.size();
        
        size_t currentIndex = 0;

        for (int num : currentLineNumbers)
        {
            if (Vector100[currentIndex].size() < 100)
            {
                // Add number to the current vector if it has space
                Vector100[currentIndex].push_back(num);
            }
            else
            {
                // Move to the next vector once the current vector has 100 elements
                currentIndex++;
                if (currentIndex >= 4) 
                {
                    std::cout << "Warning: Exceeded 4 vectors for size 100. Some data will be discarded.\n";
                    break;
                }
                Vector100[currentIndex].push_back(num); // Add number to the next vector
            }
        }

        // Clear the temporary container for the next line
        currentLineNumbers.clear();
    }

    inputFile.close();

    // Final print to show final count of vectors
    std::cout << "--- Ingest Completed. "
              << "Total vectors of size 100: " << Vector100[0].size()
              << ", " << Vector100[1].size()
              << ", " << Vector100[2].size()
              << ", " << Vector100[3].size()
              << " ---\n\n";

        // Classify data into size groups
        // if (dataSize == 100)
        // {
        //     Vector100.push_back(currentVector);
        //     //List100.push_back(currentList);
        // }
        // else if (dataSize == 1000)
        // {
        //     Vector1000.push_back(currentVector);
        //     //List1000.push_back(currentList);
        // }
        // else if (dataSize == 10000)
        // {
        //     Vector10000.push_back(currentVector);
        //     //List10000.push_back(currentList);
        // }
        // else
        // {
        //     std::cout << "Warning: Skipping data with unsupported size " << dataSize << "\n";
        // }
    }

    //inputFile.close();

    // Final print to show final count of vectors and linked lists
    // std::cout << "--- Ingest Completed. "
    //           << "Total vectors of size 100: " << Vector100.size()
    //           << ", Total linked lists of size 100: " << List100.size()
    //           << ", Total vectors of size 1000: " << Vector1000.size()
    //           << ", Total linked lists of size 1000: " << List1000.size()
    //           << ", Total vectors of size 10000: " << Vector10000.size()
    //           << ", Total linked lists of size 10000: " << List10000.size()
    //           << " ---\n\n";
    //std::cout << "total vectors of size 100:" << Vector100.size() << std::endl;

    //     // initialize for linked list
    //     DoublyLinkedList digitList;

    //     // initialize for vector
    //     std::vector<int> digitVector;
    //     while (ss >> number)
    //     {


    //         // go from number -> string in order to separate the digits
    //         std::string numStr = std::to_string(number);

    //         // fill the vector AND linked list with the individual digits
    //         for (char c : numStr)
    //         {
    //             int digit = c - '0';
    //             digitVector.push_back(digit);
    //             digitList.push_back(digit);
    //         }
    //     }

    //     int numDigits = 100;//digitVector.size();
    //     std::cout << numDigits << std::endl;

    //     if (numDigits == 100)
    //     {
    //         // Assign to the vectors of size 100
    //         Vector100[0].push_back(digitVector); // Store in the first vector of size 100
    //         List100[0].push_back(&digitList);   // Store in the first List of size 100
    //     }
    //     else if (numDigits == 1000)
    //     {
    //         // Assign to the vectors of size 1000
    //         Vector1000[0].push_back(digitVector); // Store in the first vector of size 1000
    //         List1000[0].push_back(&digitList);   // Store in the first List of size 1000
    //     }
    //     else if (numDigits == 10000)
    //     {
    //         // Assign to the vectors of size 10000
    //         Vector10000[0].push_back(digitVector); // Store in the first vector of size 10000
    //         List10000[0].push_back(&digitList);   // Store in the first List of size 10000
    //     }
    
    //     // if (num)

    //     //     // store the digit vector in the testVectors container
    //     //     testVectors.push_back(digitVector);

    //     //     // store the digit linked list in the testLists container
    //     //     testLists.push_back(digitList);

    //     //     // debug print here
    //     //     std::cout << "  Added number: " << number << " as vector: { ";
    //     //     for (int digit : digitVector)
    //     //         std::cout << digit << " ";
    //     //     std::cout << "} and as linked list: ";
    //     //     digitList.print_list();

    // }

    // inputFile.close();

    // // final print to show final count of vectors and linked lists
    // std::cout << "--- Ingest Completed. Total vectors: " << Vector100[0].size()
    //           << ", Total linked lists: " << List100[0].size() << " ---\n\n";

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

// void Evaluator::Evaluate()
// {
//     Evaluator test;
//     test.Ingest("evaluation_cases.txt");
//     test.MergeComparison();
//     test.InsertionComparison();
//     test.QuickComparison();

//     const std::vector<std::vector<int>> &testVectors = test.getTestVectors();
//     const std::vector<std::vector<double>> &vectorTimingData = test.getVectorTimingData();
//     const std::vector<std::vector<double>> &listTimingData = test.getListTimingData();

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
void Evaluator::Evaluate()
{
    //test.Ingest("evaluation_cases.txt");
    // std::vector<std::vector<int>> Vector1size100;
    // std::vector<std::vector<int>> Vector2size100;
    // std::vector<std::vector<int>> Vector3size100;
    // std::vector<std::vector<int>> Vector4size100;

    // std::vector<DoublyLinkedList*> List1size100;
    // std::vector<DoublyLinkedList*> List2size100;
    // std::vector<DoublyLinkedList*> List2size100;
    // std::vector<DoublyLinkedList*> List2size100;

    // std::vector<std::vector<int>> Vector1size1000;
    // std::vector<std::vector<int>> Vector2size1000;
    // std::vector<std::vector<int>> Vector3size1000;
    // std::vector<std::vector<int>> Vector4size1000;

    // std::vector<DoublyLinkedList*> List1size1000;
    // std::vector<DoublyLinkedList*> List2size1000;
    // std::vector<DoublyLinkedList*> List2size1000;
    // std::vector<DoublyLinkedList*> List2size1000;

    // std::vector<std::vector<int>> Vector1size10000;
    // std::vector<std::vector<int>> Vector2size10000;
    // std::vector<std::vector<int>> Vector3size10000;
    // std::vector<std::vector<int>> Vector4size10000;


    // std::vector<DoublyLinkedList*> List1size10000;
    // std::vector<DoublyLinkedList*> List2size10000;
    // std::vector<DoublyLinkedList*> List2size10000;
    // std::vector<DoublyLinkedList*> List2size10000;

    MergeComparison();
    InsertionComparison();
    QuickComparison();

    const std::vector<std::vector<int>> &testVectors = getTestVectors();
    const std::vector<std::vector<double>> &vectorTimingData = getVectorTimingData();
    const std::vector<std::vector<double>> &listTimingData = getListTimingData();

    // open the CSV file for output (use a unique file name for each run, e.g., "run1.csv")
    std::ofstream outputFile("run10.csv");
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return;
    }

    // write the CSV headers
    outputFile << "Case,Data Structure,Sort Type,Time (Seconds)" << std::endl;

    for (int i = 0; i < testVectors.size(); i++)
    {
        std::string case_number = "";
        for (int j = 0; j < testVectors[i].size(); j++)
        {
            case_number += std::to_string(testVectors[i][j]);
        }

        // write each result to the CSV file
        auto write_result = [&](double time, const std::string &container_type, const std::string &sort_type)
        {
            outputFile << case_number << "," << container_type << "," << sort_type << "," << std::fixed << std::setprecision(6) << time << std::endl;
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
    }

    // close the file after writing
    outputFile.close();
    std::cout << "Comparison results saved to 'run10.csv'!" << std::endl;
}
