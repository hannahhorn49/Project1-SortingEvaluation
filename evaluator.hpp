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
    std::vector<std::vector<int>> testVectors; // holds test cases for vectors
    std::vector<DoublyLinkedList> testLists;   // holds test cases for doubly linked lists

    std::vector<std::vector<double>> vectorTimingData; // holds timing data for vectors
    std::vector<std::vector<double>> listTimingData;   // holds timing data for linked lists

public:
    // public getters for accessing the private member variables
    const std::vector<std::vector<int>> &getTestVectors() const { return testVectors; }
    const std::vector<DoublyLinkedList> &getTestLists() const { return testLists; }
    const std::vector<std::vector<double>> &getVectorTimingData() const { return vectorTimingData; }
    const std::vector<std::vector<double>> &getListTimingData() const { return listTimingData; }

    void Ingest(const std::string &filePath);
    void MergeComparison();
    void QuickComparison();
    void InsertionComparison();
    void Evaluate();


};

#endif