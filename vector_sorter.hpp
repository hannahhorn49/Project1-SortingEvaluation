#ifndef VECTOR_SORTER_HPP
#define VECTOR_SORTER_HPP

#include <vector>

class VectorSorter
{
public:
    // these are the public sorting functions (return void bc modify input vector in place)
    static void merge_sort(std::vector<int> &vec);
    static void quick_sort(std::vector<int> &vec);
    static void insertion_sort(std::vector<int> &vec);

private:
    // these are the private helper functions for merge sort
    static void merge_sort_helper(std::vector<int> &vec, int left, int right);
    static void merge(std::vector<int> &vec, int left, int mid, int right);

    // these are the private helper functions for quick sort
    static void quick_sort_helper(std::vector<int> &vec, int left, int right);
    // returns int bc returns new index of the pivot element
    static int partition(std::vector<int> &vec, int left, int right);
};

#endif