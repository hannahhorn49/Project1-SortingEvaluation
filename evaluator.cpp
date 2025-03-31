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
    std::cout << "Ingest() started" << std::endl;

    std::ifstream inputFile(filePath); // open file
    if (!inputFile.is_open())
    {
        std::cout << "Error: Could not open file: " << filePath << std::endl; // check if file is opened
        return;
    }

    std::string line;
    int lineCount = 0;

    // debuggin
    std::cout << "Starting file ingestion from: " << filePath << std::endl;

    // loop through each line of file
    while (std::getline(inputFile, line))
    {

        std::vector<int> currentLineNumbers;
        DoublyLinkedList currentList;
        ++lineCount;
        std::stringstream ss(line);
        std::string number;

        // std::cout << "Line " << lineCount << ": " << line << "\n";

        // read all numbers in this line
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
    std::cout << "File ingestion complete. Processed " << lineCount << " lines.\n";
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
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData100.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // debuggin more
        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData100.back() << " ms\n";

        Vector100[i] = vecCopy; // update original vector with sorted values

        // work with a linked list
        DoublyLinkedList &list = List100[i];
        // debugging step: make sure list is empty
        list.clear();
        // DoublyLinkedList originalList = list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();

        // list.DLL_insertion_sort(list.get_head());
        list.DLL_insertion_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData100.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_partial_list();
        // std::cout << "Time: " << listTimingData100.back() << " ms\n";

        List100[i] = list;
    }

    // LOOP 2
    for (size_t i = 0; i < Vector1000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData1000.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData1000.back() << " ms\n";

        Vector1000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List1000[i];
        list.clear();
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_insertion_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        // std::cout << "Sorted linked list " << i << ": ";
        //  list.print_partial_list();
        //  std::cout << "Time: " << listTimingData1000.back() << " ms\n";

        List1000[i] = list;
    }

    // LOOP 3
    for (size_t i = 0; i < Vector10000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector10000[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::insertion_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData10000.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData10000.back() << " ms\n";

        Vector10000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List10000[i];
        list.clear();
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_insertion_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData10000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_list();
        // std::cout << "} Time: " << listTimingData10000.back() << " ms\n";

        List10000[i] = list;
    }

    std::cout << "--- InsertionComparison Completed ---\n\n";
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
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::quick_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData100.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // debuggin more
        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData100.back() << " ms\n";

        Vector100[i] = vecCopy; // update original vector with sorted values

        // work with a linked list
        DoublyLinkedList &list = List100[i];
        // debugging step: make sure list is empty
        list.clear();
        // DoublyLinkedList originalList = list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();

        // list.DLL_insertion_sort(list.get_head());
        list.DLL_quick_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData100.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_partial_list();
        // std::cout << "Time: " << listTimingData100.back() << " ms\n";

        List100[i] = list;
    }

    // LOOP 2
    for (size_t i = 0; i < Vector1000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::quick_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData1000.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData1000.back() << " ms\n";

        Vector1000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List1000[i];
        list.clear();
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_quick_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_partial_list();
        // std::cout << "Time: " << listTimingData1000.back() << " ms\n";

        List1000[i] = list;
    }

    //std::cout << "past loop 2" << std::endl;
    //std::cout << listTimingData1000.size() << std::endl;
    // LOOP 3
    for (size_t i = 0; i < Vector10000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector10000[i];
        std::vector<int> vecCopy = vec;
        // for (int i = 0; i < vecCopy.size(); i ++)
        // {
        //     std::cout << vecCopy[i] << std::endl;
        // }
        //std::cout << "Original vector " << i << ": ";
        //VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        //std::cout << "past timing" << std::endl;
        VectorSorter::quick_sort(vecCopy);
        //std::cout << "past initiation" << std::endl;
        auto end = std::chrono::high_resolution_clock::now();
        //std::cout << vectorTimingData10000.size() << std::endl;
        vectorTimingData10000.push_back(std::chrono::duration<double, std::milli>(end - start).count());


        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData10000.back() << " ms\n";

        Vector10000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List10000[i];
        list.clear();
        for (int val : vec)
        {
            list.push_back(val);
        }
        //std::cout << "past loop 3" << std::endl;


        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_quick_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData10000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_list();
        // std::cout << "} Time: " << listTimingData10000.back() << " ms\n";

        List10000[i] = list;
    }

    std::cout << "--- QuickComparison Completed ---\n\n";
}

void Evaluator::MergeComparison()
{
    std::cout << "\n--- Starting MergeComparison ---\n";

    // LOOP 1
    std::cout << Vector100.size() << std::endl;
    for (size_t i = 0; i < Vector100.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector100[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData100.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // debuggin more
        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData100.back() << " ms\n";

        Vector100[i] = vecCopy; // update original vector with sorted values

        // work with a linked list
        DoublyLinkedList &list = List100[i];
        // debugging step: make sure list is empty
        list.clear();
        // DoublyLinkedList originalList = list;
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();

        // list.DLL_insertion_sort(list.get_head());
        list.DLL_merge_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData100.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_partial_list();
        // std::cout << "Time: " << listTimingData100.back() << " ms\n";

        List100[i] = list;
    }

    // LOOP 2
    for (size_t i = 0; i < Vector1000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector1000[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData1000.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData1000.back() << " ms\n";

        Vector1000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List1000[i];
        list.clear();
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_merge_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData1000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        List1000[i] = list;
    }

    // LOOP 3
    for (size_t i = 0; i < Vector10000.size(); ++i)
    {
        // get reference to test vector and create a sorted copy
        auto &vec = Vector10000[i];
        std::vector<int> vecCopy = vec;

        // for debuggin!!
        // std::cout << "Original vector " << i << ": ";
        // VectorSorter::print_vector(vec); // Print first 3 and last 3 elements

        // measuring sorting time
        auto start = std::chrono::high_resolution_clock::now();
        VectorSorter::merge_sort(vecCopy);
        auto end = std::chrono::high_resolution_clock::now();
        vectorTimingData10000.push_back(std::chrono::duration<double, std::milli>(end - start).count());

        // std::cout << "Sorted vector " << i << ": ";
        // VectorSorter::print_vector(vecCopy);
        // std::cout << "Time: " << vectorTimingData10000.back() << " ms\n";

        Vector10000[i] = vecCopy; // update original vector with sorted values

        DoublyLinkedList &list = List10000[i];
        list.clear();
        for (int val : vec)
        {
            list.push_back(val);
        }

        // DoublyLinkedList originalList = list;

        // debuggin!
        // std::cout << "Original linked list " << i << ": ";
        // list.print_partial_list(); // Print first 3 and last 3 elements

        if (list.get_head() == nullptr)
        {
            std::cout << "Warning: List " << i << " is empty, skipping sort.\n";
            continue;
        }

        // sort the original linked list and measure time
        auto listStart = std::chrono::high_resolution_clock::now();
        list.DLL_merge_sort(list.get_head());
        auto listEnd = std::chrono::high_resolution_clock::now();
        listTimingData10000.push_back({std::chrono::duration<double, std::milli>(listEnd - listStart).count()});

        // print the sorted linked list
        // std::cout << "Sorted linked list " << i << ": ";
        // list.print_list();
        // std::cout << "} Time: " << listTimingData10000.back() << " ms\n";

        List10000[i] = list;
    }

    std::cout << "--- MergeComparison Completed ---\n\n";
}

void Evaluator::Evaluate()
{
    vectorTimingData10000.clear();

    Ingest("evaluation_cases.txt");
    MergeComparison();
    //std::cout << "MERGE:" << vectorTimingData100.size() << std::endl;
    InsertionComparison();
    QuickComparison();

    std::cout << "Size of vectorTimingData100: " << vectorTimingData100.size() << std::endl;
    std::cout << "Size of vectorTimingData1000: " << vectorTimingData1000.size() << std::endl;
    std::cout << "Size of vectorTimingData10000: " << vectorTimingData10000.size() << std::endl;


    //FOR MERGE!! 
    std::cout << "-------------------------------------Time of Comparisons (MERGE)-------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "||---------size----------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- ||" << std::endl;

    //size 100
    std::cout << "|-----------100------------ | -------- " << vectorTimingData100[0] << "----------|---------------  Vector  ---------------|" << std::endl;
    std::cout << "|-----------100------------ | -------- " << vectorTimingData100[1] << "----------|---------------  Vector  ---------------|" << std::endl;
    std::cout << "|-----------100------------ | -------- " << vectorTimingData100[2] << "----------|---------------  Vector  ---------------|" << std::endl;
    std::cout << "|-----------100------------ | -------- " << vectorTimingData100[3] << "----------|---------------  Vector  ---------------|" << std::endl;
 
    std::cout << "|-----------100------------- | -------- " << listTimingData100[0] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    std::cout << "|-----------100------------- | -------- " << listTimingData100[1] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    std::cout << "|-----------100------------- | -------- " << listTimingData100[2] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    std::cout << "|-----------100------------- | -------- " << listTimingData100[3] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
    
    
    //size 1000
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|-----------1000------------ | -------- " << vectorTimingData1000[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|-----------1000------------- | -------- " << listTimingData1000[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
    
    //size 10000
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|-----------10000------------ | -------- " << vectorTimingData10000[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        std::cout << "|-----------10000------------- | -------- " << listTimingData10000[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
     

    std::cout << "" <<std::endl;
    std::cout << "" <<std::endl;
    //FOR INSERTION!
    std::cout << "-----------------------------------Time of Comparisons (INSERTION)-----------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "||---------size----------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- ||" << std::endl;
    for (int i = 4; i < 8; i++)
    {
        std::cout << "|-----------100------------ | -------- " << vectorTimingData100[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 4; i < 8; i++)
    {
        std::cout << "|-----------100------------- | -------- " << listTimingData100[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

    //size 1000
    for (int i = 4; i < 8; i++)
    {
        std::cout << "|-----------1000------------ | -------- " << vectorTimingData1000[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 4; i < 8; i++)
    {
        std::cout << "|-----------1000------------- | -------- " << listTimingData1000[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

    //size 10000
    for (int i = 4; i < 8; i++)
    {
        std::cout << "|-----------10000------------ | -------- " << vectorTimingData10000[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 4; i < 8; i++)
    {
        std::cout << "|-----------10000------------- | -------- " << listTimingData10000[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

    std::cout << "" <<std::endl;
    std::cout << "" <<std::endl;
    //FOR QUICK 
    std::cout << "-------------------------------------Time of Comparisons (QUICK)-------------------------------------" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "||---------size----------- | ------- TIME IT TOOK ------- | ------- Vector/Linked List ------- ||" << std::endl;
    for (int i = 8; i < 12; i++)
    {
        std::cout << "|-----------100------------ | -------- " << vectorTimingData100[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 8; i < 12; i++)
    {
        std::cout << "|-----------100------------- | -------- " << listTimingData100[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

    //size 1000
    for (int i = 8; i < 12; i++)
    {
        std::cout << "|-----------1000------------ | -------- " << vectorTimingData1000[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 8; i < 12; i++)
    {
        std::cout << "|-----------1000------------- | -------- " << listTimingData1000[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

    //size 10000
    for (int i = 8; i < 12; i++)
    {
        std::cout << "|-----------10000------------ | -------- " << vectorTimingData10000[i] << "----------|---------------  Vector  ---------------|" << std::endl;
    }
    for (int i = 8; i < 12; i++)
    {
        std::cout << "|-----------10000------------- | -------- " << listTimingData10000[i] << "--------|---------------  Linked List  ---------------|" <<  std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

}