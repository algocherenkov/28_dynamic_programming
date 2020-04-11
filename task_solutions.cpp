#include "task_solutions.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>

struct FractionsData {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
};

FractionsData parseData(std::string &input)
{
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    FractionsData result;

    auto divPos = input.find_first_of('/');
    if(divPos == std::string::npos)
    {
        std::cerr << "wrong input. No 'division' sign" << std::endl;
        return FractionsData{-1, -1, -1, -1};
    }

    auto a_str = input.substr(0, divPos);
    result.a = atoi(a_str.c_str());

    auto signPos = input.find_first_of("+-", divPos);
    if(signPos == std::string::npos)
    {
        std::cerr << "wrong input.No 'operator' sign" << std::endl;
        return FractionsData{-1, -1, -1, -1};
    }

    auto b_str = input.substr(divPos + 1, signPos - divPos - 1);
    result.b = atoi(b_str.c_str());

    auto divPos2 = input.find_first_of('/', signPos);
    if(divPos2 == std::string::npos)
    {
        std::cerr << "wrong input. No 'division' sign" << std::endl;
        return FractionsData{-1, -1, -1, -1};
    }

    auto c_str = input.substr(signPos, divPos2);
    result.c = atoi(c_str.c_str());

    auto d_str = input.substr(divPos2 + 1);
    result.d = atoi(d_str.c_str());

    return result;
}

bool even(int x) { return (x & 1) == 0; }
bool odd(int x) { return (x & 1) == 1; }

int gcd(int x, int y)
{
    if(x == y) return x;
    if(x == 0) return y;
    if(y == 0) return x;

    if(even(x) && even(y)) return 2 * gcd(x/2, y/2);
    if(even(x) && odd(y)) return gcd(x/2, y);
    if(odd(x) && even(y)) return gcd(x, y/2);

    if(x > y) return gcd((x - y) / 2, y);
    return gcd(x, (y - x) / 2);
}

std::pair<int, int> tasks::oneDivTwoPeas(std::string &input)
{
    auto data = parseData(input);
    int x = data.a * data.d + data.b * data.c;
    int y = data.b * data.d;

    int g = gcd(x, y);
    x /= g;
    y /= g;

    return std::pair<int,int>(x,y);
}

int tasks::furTreeGarlandValue(int tree[][100], int height)
{
    for(int i = height - 2; i >= 0 ; i--)
        for(int j = 0; j <= i; j++)
            tree[i][j] += std::max(tree[i + 1][j], tree[i + 1][j + 1]);
    return tree[0][0];
}
