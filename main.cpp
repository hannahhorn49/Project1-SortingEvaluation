// supposed to call evaluate here
#include "evaluator.hpp"
#include "doubly_linked_list.hpp"
#include <iostream>
#include <cassert>
#include "vector_sorter.hpp"


int main()
{
    Evaluator tester;

    //void Evaluator::Evaluate()
    //test.Ingest("evaluation_cases.txt");
    // std::vector<std::vector<int>> Vector1size100;
    // std::vector<std::vector<int>> Vector2size100;
    // std::vector<std::vector<int>> Vector3size100;
    // std::vector<std::vector<int>> Vector4size100;

    // std::vector<DoublyLinkedList*> List1size100;
    // std::vector<DoublyLinkedList*> List2size100;
    // std::vector<DoublyLinkedList*> List2size100;
    // std::vector<DoublyLinkedList*> List2size100;

    // std::vector<std::vector<int>> Vector1size1000;
    // std::vector<std::vector<int>> Vector2size1000;
    // std::vector<std::vector<int>> Vector3size1000;
    // std::vector<std::vector<int>> Vector4size1000;

    // std::vector<DoublyLinkedList*> List1size1000;
    // std::vector<DoublyLinkedList*> List2size1000;
    // std::vector<DoublyLinkedList*> List2size1000;
    // std::vector<DoublyLinkedList*> List2size1000;

    // std::vector<std::vector<int>> Vector1size10000;
    // std::vector<std::vector<int>> Vector2size10000;
    // std::vector<std::vector<int>> Vector3size10000;
    // std::vector<std::vector<int>> Vector4size10000;


    // std::vector<DoublyLinkedList*> List1size10000;
    // std::vector<DoublyLinkedList*> List2size10000;
    // std::vector<DoublyLinkedList*> List2size10000;
    // std::vector<DoublyLinkedList*> List2size10000;

    tester.Ingest("evaluation_cases.txt");
    tester.Evaluate();
    return 0;
}