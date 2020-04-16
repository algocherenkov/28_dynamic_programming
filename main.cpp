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
    tasks::OneTwoPeas solver;
    solver.setData(input);
    auto result = solver.calc();

    BOOST_CHECK_MESSAGE(result.first == 1, "nominator is wrong. Real value is " << result.first);
    BOOST_CHECK_MESSAGE(result.second == 20, "denominator is wrong. Real value is " << result.second);
}

BOOST_AUTO_TEST_CASE(fur_tree_test)
{
    //generate fur tree from lesson
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

BOOST_AUTO_TEST_CASE(small_barn_finder_tests)
{
    int N = 4;
    int M = 3;
    int field[30][30] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };

    tasks::BarnFinder barnFinder(N, M);
    barnFinder.fillField(field);
    auto result = barnFinder.calcWithBruteForce();

    BOOST_CHECK_MESSAGE(result == 6, "wrong value of square. Result is " << result);
}

BOOST_AUTO_TEST_CASE(barn_finder_part_one_tests)
{
    int N = 4;
    int M = 3;
    int T = 2;
    int coords[2][30] = {
        {1, 1},
        {0, 2}
    };

    int answer[30][30];

    tasks::BarnFinder barnFinder(N, M);
    barnFinder.fillTreeCoords(coords, T);
    barnFinder.calcMatrixLengthsAboveCells();
    barnFinder.printMatrixLengthsAboveCells();

    barnFinder.getMatrixLengthsAboveCells(answer);

    BOOST_CHECK_MESSAGE(answer[1][1] == 0, "wrong value. Result is " << answer[1][1]);
    BOOST_CHECK_MESSAGE(answer[2][0] == 0, "wrong value. Result is " << answer[2][0]);
    BOOST_CHECK_MESSAGE(answer[2][3] == 3, "wrong value. Result is " << answer[2][3]);
}

BOOST_AUTO_TEST_CASE(barn_finder_part_two_tests)
{
    int M = 4;
    int N = 10;
    int buff[10] = {1, 1, 1, 4, 4, 2, 3, 3, 2, 2};
    int answerL[10] = {0, 0, 0, 3, 3, 3, 6, 6, 3, 3};
    int answerR[10] = {9, 9, 9, 4, 4, 9, 7, 7, 9, 9};

    tasks::BarnFinder barnFinder(N, M);
    barnFinder.fillBuff(buff);
    barnFinder.calcLRBuffs();
    barnFinder.printLRBuffs();

    auto lBuffer = barnFinder.getLBuff();
    auto rBuffer = barnFinder.getRBuff();

    for(int i = 0; i < N; i++)
    {
        BOOST_CHECK_MESSAGE(lBuffer[i] == answerL[i], "wrong value in lBuffer. Index is " << i << ". Real value is " << answerL[i]);
        BOOST_CHECK_MESSAGE(rBuffer[i] == answerR[i], "wrong value in lBuffer. Index is " << i << ". Real value is " << answerL[i]);
    }

    barnFinder.clearBuffs();

    int buff2[10] = {6, 5, 4, 3, 2, 1, 0, 1, 2, 3};
    int answerL2[10] = { 0, 0, 0, 0, 0, 0, 0, 7, 8, 9 };
    int answerR2[10] = { 0, 1, 2, 3, 4, 5, 9, 9, 9, 9 };
    barnFinder.fillBuff(buff2);
    barnFinder.calcLRBuffs();
    barnFinder.printLRBuffs();

    auto lBuffer2 = barnFinder.getLBuff();
    auto rBuffer2 = barnFinder.getRBuff();

    for (int i = 0; i < N; i++)
    {
        BOOST_CHECK_MESSAGE(lBuffer2[i] == answerL2[i], "wrong value in lBuffer. Index is " << i << ". Real value is " << answerL2[i]);
        BOOST_CHECK_MESSAGE(rBuffer2[i] == answerR2[i], "wrong value in lBuffer. Index is " << i << ". Real value is " << answerL2[i]);
    }
}
BOOST_AUTO_TEST_SUITE_END()
