# Project1-SortingEvaluation


**TO RUN: testing sorting**
g++ -std=c++11 test_sorting.cpp vector_sorter.cpp doubly_linked_list.cpp

./a.out

**TO RUN: the evaluator**
g++ -std=c++11 test_evaluator.cpp vector_sorter.cpp doubly_linked_list.cpp evaluator.cpp

./a.out

**TO RUN: the evaluator for windows:**
g++ -o program test_evaluator.cpp vector_sorter.cpp doubly_linked_list.cpp evaluator.cpp -o evaluator

./evaluator.exe


**TO RUN: the evaluation**
g++ -std=c++11 main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp

./a.out  

**FOR WINDOWS: the evaluation:**
g++ -O2 -std=c++11 "-Wl,--stack=268435456" -o program main.cpp evaluator.cpp doubly_linked_list.cpp vector_sorter.cpp -o evaluate

./evaluate.exe
