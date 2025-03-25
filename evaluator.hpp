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
    std::vector<std::vector<int>> testVectors;
    // std::vector<DoublyLinkedList<int>> testLists;
    std::vector<std::vector<double>> timingData;

    //OR WOULD I CREATE A VECTOR TO HOLD THE LINKED LISTS
    DoublyLinkedList testLists;

public:

    DoublyLinkedList &getTestList() {return testLists;}

    const std::vector<std::vector<int>> &getTestVectors() const { return testVectors; }
    const std::vector<std::vector<double>> &getTimingData() const { return timingData; }

    void Ingest(const std::string &filePath);
    void MergeComparison();
    void QuickComparison();
    void InsertionComparison();
    void Evaluate() const;
};

#endif