#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include "vector_sorter.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void Evaluator::Ingest(const std::string &filePath)
{
    std::ifstream inputFile(filePath); // open the file for reading

    if (!inputFile.is_open()) // checks if file opened successfully
    {
        std::cout << "Error: Could not open file: " << filePath << std::endl;
        return;
    }

    std::string line; // holds each line from the file

    // here reads the file line by line
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line); // turns the line into a stringstream for parsing numbers
        int number;

        // this loop extracts each "section" of numbers
        while (ss >> number)
        {
            std::vector<int> singleNumberVector;
            singleNumberVector.push_back(number); // just puts "one number" in the vector

            testVectors.push_back(singleNumberVector); // stores this individual vector in the testVectors

            // debugging
            std::cout << "Added vector: { " << number << " }" << std::endl;
        }
    }

    inputFile.close(); // close the file when done
}
