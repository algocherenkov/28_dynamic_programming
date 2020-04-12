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

    BOOST_CHECK_MESSAGE(result.first == 1, "nominator is wrong. Real value is " << result.first);
    BOOST_CHECK_MESSAGE(result.second == 20, "denominator is wrong. Real value is " << result.second);
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

    BOOST_CHECK_MESSAGE(result == 17, "wrong value for tree from lesson. Result is " << result);
}

BOOST_AUTO_TEST_CASE(five_on_eight_test)
{
    int n = 3;

    auto result = tasks::fiveOnEight(n);

    BOOST_CHECK_MESSAGE(result == 6, "wrong value for n = " << n << ". Result is " << result);

    n = 4;

    result = tasks::fiveOnEight(n);

    BOOST_CHECK_MESSAGE(result == 10, "wrong value for n = " << n << ". Result is " << result);
}

BOOST_AUTO_TEST_CASE(islands_test)
{
    int n = 4;
    int ocean[100][100] = {
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 1, 1}
    };

    auto result = tasks::islandsInMatrix(ocean, n);

    BOOST_CHECK_MESSAGE(result == 3, "wrong value of islands for n = " << n << ". Result is " << result);


    n = 10;
    int ocean2[100][100] = {
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 1}
    };

    result = tasks::islandsInMatrix(ocean2, n);

    BOOST_CHECK_MESSAGE(result == 11, "wrong value of islands for n = " << n << ". Result is " << result);
}

BOOST_AUTO_TEST_CASE(small_barn_test)
{
    int N = 4;
    int M = 3;
    int tree[30][30] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };

    tasks::SmallBarn barnFinder(N, M);
    barnFinder.fillField(tree);
    auto result = barnFinder.calc();

    BOOST_CHECK_MESSAGE(result == 6, "wrong value of square. Result is " << result);
}
BOOST_AUTO_TEST_SUITE_END()
