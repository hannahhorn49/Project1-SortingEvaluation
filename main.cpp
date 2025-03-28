// supposed to call evaluate here
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include <iostream>
#include <cassert>
#include "vector_sorter.hpp"


int main()
{
    Evaluator tester;
    tester.Ingest("evaluation_cases.txt");
    //tester.Evaluate();
    return 0;
}