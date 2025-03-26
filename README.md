# Project1-SortingEvaluation

`Should tell the user how to run our code in three different instances:`
- testing sorting (both data types)
- testing the evaluator
- running the evaluation


**TO RUN: testing sorting**
g++ -std=c++11 test_sorting.cpp vector_sorter.cpp doubly_linked_list.cpp

./a.out

**TO RUN: the evaluator**
g++ -std=c++11 test_evaluator.cpp vector_sorter.cpp doubly_linked_list.cpp evaluator.cpp

./a.out

**TO RUN: the evaluation**
g++ -o program main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o evaluate

./evaluate.exe