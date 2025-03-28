#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <vector>
#include <string>
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <chrono> // this is a way we can time our sorts

class Evaluator
{
private:
    // these are the member variables to store the evaluation cases and timing data
    //std::vector<std::vector<int>> testVectors; // holds test cases for vectors
    //std::vector<DoublyLinkedList> testLists;   // holds test cases for doubly linked lists
    // Vectors to hold different sizes of data
    std::vector<std::vector<int>> Vector100;
    std::vector<std::vector<int>> Vector1000;
    std::vector<std::vector<int>> Vector10000;

    std::vector<DoublyLinkedList> List100;
    std::vector<DoublyLinkedList> List1000;
    std::vector<DoublyLinkedList> List10000;

    std::vector<std::vector<double>> vectorTimingData; // holds timing data for vectors
    std::vector<std::vector<double>> listTimingData;   // holds timing data for linked lists

public:
    // public getters for accessing the private member variables
    const std::vector<std::vector<int>> &getTestVectors100() const { return Vector100; }
    const std::vector<std::vector<int>> &getTestVectors1000() const { return Vector1000; }
    const std::vector<std::vector<int>> &getTestVectors10000() const { return Vector10000; }

    const std::vector<DoublyLinkedList> &getTestLists100() const { return List100; }
    const std::vector<DoublyLinkedList> &getTestLists1000() const { return List1000; }
    const std::vector<DoublyLinkedList> &getTestLists10000() const { return List10000; }


    const std::vector<std::vector<double>> &getVectorTimingData() const { return vectorTimingData; }
    const std::vector<std::vector<double>> &getListTimingData() const { return listTimingData; }

    void Ingest(const std::string &filePath);
    void MergeComparison();
    void QuickComparison();
    void InsertionComparison();
    void Evaluate();


};

#endif