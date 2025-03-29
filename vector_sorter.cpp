#include "vector_sorter.hpp"
#include <iostream>

void VectorSorter::merge_sort(std::vector<int> &vec)
{
    // this function starts the recursive process
    merge_sort_helper(vec, 0, vec.size() - 1); // note: subtract 1 to make sure it's in range bc zero index
}

void VectorSorter::merge_sort_helper(std::vector<int> &vec, int left, int right)
{
    // this is where the recursion happens (splits the vector into halves and recursively sorts each half)

    // base case (we stop recursing if vector has one or zero elements)
    if (left >= right) // this works bc one element (indexes are equal) and no elements (left = 0, right = size-1 = -1 so 0 >=-1)
    {
        return; // means already "sorted"
    }

    // need to find the middle of the current sub section of vector
    int mid = left + (right - left) / 2;
    // ex. vec = {38, 27, 43, 3, 9, 82, 10} -> merge_sort_helper(vec, 0, 6)
    // midpoint = 3
    // left [0..3] = {38,27,43,3}
    // right [4..6] = {9,82,10}

    // next have to recursively sort the left and right halves
    merge_sort_helper(vec, left, mid);      // ex. merge_sort_helper(vec, 0, 3) for left half
    merge_sort_helper(vec, mid + 1, right); // ex. merge_sort_helper(vec, 4, 6) for right half

    // this part will continuously divide the vector until it reaches the base case of a single element
    // e.g. wil call merge_sort_helper(vec, 0, 3)

    // now that everything is split we call merge function to merge the sorted halves
    merge(vec, left, mid, right);
}

void VectorSorter::merge(std::vector<int> &vec, int left, int mid, int right)
{
    // walking through with example vec = {27,38,3,43}
    // left subvector = {27,38}
    // right subvector = {3,43}
    // std::cout << "Merging vec[" << left << ".." << mid << "] and vec[" << mid + 1 << ".." << right << "]" << std::endl;
    // will output: Merging vec[0..1] and vec[2..3]

    // first need to create a temp vector to store merged results
    std::vector<int> temp;

    // need to create variables that hold the beginning of each left and right subvector
    int i = left, j = mid + 1;

    // here for debugging purposes (to ensure elements in left side)
    // std::cout << "Left subarray: ";
    // for (int k = left; k <= mid; ++k)
    // {
    //     std::cout << vec[k] << " ";
    // }
    // std::cout << std::endl;

    // will output: Left subarray: 27 38

    // here for debugging purposes (to ensure elements in right side)
    // std::cout << "Right subarray: ";
    // for (int k = mid + 1; k <= right; ++k)
    // {
    //     std::cout << vec[k] << " ";
    // }
    // std::cout << std::endl;

    // will output: Right subarray: 3 43

    // start the merging process here where i = 0 (start of left), j = 2 (start of right)
    // we merge into the temp vector
    while (i <= mid && j <= right) // loop will continue as long as both i is within the left subsection and j is within the right subsection
    {
        // std::cout << "Comparing " << vec[i] << " and " << vec[j] << std::endl;
        // iteration 1a: Comparing 27 and 3
        // iteration 2a: Comparing 27 and 43
        // iteration 3a: Comparing 38 and 43

        if (vec[i] <= vec[j])
        {
            // iteration 2b: since 27 <= 43, place 27 into position 1
            // iteration 3b: since 38 <= 43, place 38 into position 2
            // std::cout << "Placing " << vec[i] << " into position " << (left + temp.size()) << std::endl;
            temp.push_back(vec[i++]); // increment i to move to next positon in vec
            // iteration2 vector: {3, 27}
            // iteration3 vector: {3,27,38}
        }
        else
        {
            // iteration 1b: since 27 is NOT <= 3, place 3 into positon 0
            // std::cout << "Placing " << vec[j] << " into position " << (left + temp.size()) << std::endl;
            temp.push_back(vec[j++]); // increment j to move to next positon in vec
            // iteration1 vector: {3}
        }
    }

    // since right subsection is empty -> copy remaining elements from left
    while (i <= mid)
    {
        // std::cout << "Copying remaining " << vec[i] << " from the left subarray into position " << (left + temp.size()) << std::endl;
        temp.push_back(vec[i++]);
    }

    // since left subsection is empty -> copy remaining elements from right
    // in our example: left is empty (27 38) and right has 43 remaining so..
    while (j <= right)
    {
        // std::cout << "Copying remaining " << vec[j] << " from the right subarray into position " << (left + temp.size()) << std::endl;
        // will output: Copying remaining 43 from the right subarray into position 3
        temp.push_back(vec[j++]);
        // final temp vector looks like this: {3, 27, 38, 43}
    }

    // the merged temp values are written to their correct positions in vec
    for (int k = 0; k < temp.size(); ++k)
    {
        // std::cout << "Writing " << temp[k] << " to vec[" << (left + k) << "]" << std::endl;
        vec[left + k] = temp[k];
        // will output: Writing 3 to vec[0], Writing 27 to vec[1]...
    }

    // just here for debugging purposes to see the final output
    // std::cout << "Merged vec[" << left << ".." << right << "]: ";
    // for (int k = left; k <= right; ++k)
    // {
    //     std::cout << vec[k] << " ";
    // }
    // std::cout << std::endl
    //           << std::endl;
}

void VectorSorter::quick_sort(std::vector<int> &vec)
{
    // this function starts the recursive process
    quick_sort_helper(vec, 0, vec.size() - 1);
}

void VectorSorter::quick_sort_helper(std::vector<int> &vec, int left, int right)
{
    // base case here (if the vector/subvector has one or zero elements we don't do anything)
    if (left < right)
    {
        // first thing is choosing a pivot (always pick first element of current sub vector)
        int pivot = vec[left];

        // this is just for debugging (showing pivot and current subvector being worked on)
        // std::cout << "Pivot: " << pivot << " | Subvector: ";
        // for (int i = left; i <= right; i++)
        // {
        //     std::cout << vec[i] << " ";
        // }
        // std::cout << "\n";

        // once we have pivot, we create two temporary vectors that we will partition elements into
        // left = smaller than pivot and right = bigger than pivot
        std::vector<int> leftPart;
        std::vector<int> rightPart;

        // this part loops through the subvector (NOT INCLUDING PIVOT) and divides the elements into smaller and larger
        for (int i = left + 1; i <= right; i++)
        {
            if (vec[i] < pivot)
                leftPart.push_back(vec[i]); // here we put smaller elements on the left
            else
                rightPart.push_back(vec[i]); // here we put larger elements on the right
        }

        // now we rebuild the original vector using the leftPart + rightPart
        // first insert the values less than pivot (all elements in leftPart)
        int idx = left;
        for (int val : leftPart)
        {
            vec[idx++] = val;
        }

        // next in our rebuilding we place the pivot in the correct sorted position
        int pivotIndex = idx; // note: this is the final position for this number
        vec[idx++] = pivot;

        // now that we have the left part, middle, we add all larger elements (rightPart)
        for (int val : rightPart)
        {
            vec[idx++] = val;
        }

        // here for debugging, showing vector after partitioning
        // std::cout << "After partition: ";
        // for (int i = left; i <= right; i++)
        // {
        //     std::cout << vec[i] << " ";
        // }
        // std::cout << " | Pivot index: " << pivotIndex << "\n\n";

        // last part is just applying quick sort recurively on these left and right parts
        quick_sort_helper(vec, left, pivotIndex - 1);
        quick_sort_helper(vec, pivotIndex + 1, right);
    }
}

void VectorSorter::insertion_sort(std::vector<int> &vec)
{
    // case 1: empty
    if (vec.size() == 0)
    {
    }
    // everything else: incldues the vectors with same numbers
    else
    {
        for (int i = 1; i < vec.size(); i++)
        {
            int cursor = i;
            int temp = vec[i];
            while (cursor > 0 && temp < vec[cursor - 1])
            {
                vec[cursor] = vec[cursor - 1];
                cursor--;
            }
            vec[cursor] = temp;
        }
    }
}
