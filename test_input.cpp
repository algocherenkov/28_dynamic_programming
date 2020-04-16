#include "task_solutions.h"
#include <iostream>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N;

    tasks::BarnFinder barnFinder(N, M);
    barnFinder.readBuff();
    barnFinder.calcLRBuffs(nullptr);

    barnFinder.printLRBuffs();
    getchar();
}
