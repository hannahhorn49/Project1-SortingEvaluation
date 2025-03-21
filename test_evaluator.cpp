#include "evaluator.hpp"
#include <iostream>
#include <cassert>

bool testIngest()
{
    // NOTE: just going to write for vectors right now

    // set up (create an instance of Evaluator class)
    Evaluator evaluator;

    // execution (calling the Ingest function)
    evaluator.Ingest("test_cases.txt");

    // validation
    std::vector<std::vector<int>> expectedVectors = {
        {1273}, {4577}, {1586}, {61407}, {53249}, {41309}, {736525}, {835483}, {306449}};

    const std::vector<std::vector<int>> &actualVectors = evaluator.getTestVectors();
    assert(actualVectors.size() == expectedVectors.size());

    for (int i = 0; i < expectedVectors.size(); ++i)
    {
        assert(actualVectors[i] == expectedVectors[i]);
    }

    std::cout << "Vector ingest test passed!\n";

    // clean up
    return true;
}

void testMergeComparison()
{
    // set up

    // execution

    // validation

    // clean up
}

void testQuickComparison()
{
    // set up

    // execution

    // validation

    // clean up
}

void testInsertionComparison()
{
    // set up

    // execution

    // validation

    // clean up
}

void testEvaluate()
{
    // set up

    // execution

    // validation

    // clean up
}