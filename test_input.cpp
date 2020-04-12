#include "task_solutions.h"
#include <iostream>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N;
    std::cin >> M;
    tasks::SmallBarn barnFinder(N, M);
    barnFinder.readField();

    std::cout << barnFinder.calc() << std::endl;

    getchar();
}
