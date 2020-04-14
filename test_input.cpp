#include "task_solutions.h"
#include <iostream>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N;
    std::cin >> M;
    tasks::BarnFinder barnFinder(N, M);
    barnFinder.readTreeCoords();
    barnFinder.calcMatrixLengthsAboveCells();

    barnFinder.printMatrixLengthsAboveCells();
    getchar();
}
