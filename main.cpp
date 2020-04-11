#include "task_solutions.h"
#include <string>
#include <ctime>
#include <chrono>
#include <random>
#include <iterator>
#include <map>
#include <cstdio>

#define BOOST_TEST_MODULE test_main

#include <boost/test/included/unit_test.hpp>

using namespace boost::unit_test;
BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(one_division_two_peas_test)
{
    std::string input("2/100+3/100");
    auto result = tasks::oneDivTwoPeas(input);

    BOOST_CHECK_MESSAGE(result.first == 1, "nominator is wrong");
    BOOST_CHECK_MESSAGE(result.second == 20, "denominator is wrong");
}

BOOST_AUTO_TEST_CASE(fur_tree_test)
{
    int tree[100][100];

    int k = 1;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <= i; j++)
            tree[i][j] = k++;

    tree[3][0] = 9; tree[3][1] = 8; tree[3][2] = 0; tree[3][3] = 4;

    auto result = tasks::furTreeGarlandValue(tree, 4);

    BOOST_CHECK_MESSAGE(result == 17, "wrong value for tree from lesson");
}


BOOST_AUTO_TEST_SUITE_END()
