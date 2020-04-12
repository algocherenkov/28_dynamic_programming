#include "task_solutions.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>

namespace {

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

void walk(int x, int y, int ocean[][100], int n)
{
    if(x < 0 || x > n) return;
    if(y < 0 || y > n) return;
    if(ocean[x][y] == 0) return;

    ocean[x][y] = 0;

    walk(x - 1, y, ocean, n);
    walk(x + 1, y, ocean, n);
    walk(x, y - 1, ocean, n);
    walk(x, y + 1, ocean, n);
}
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

int tasks::fiveOnEight(int n)
{
    int x5 = 1;
    int x8 = 1;
    int x55 = 0;
    int x88 = 0;

    int f5 = 0;
    int f8 = 0;

    for(int i = 2; i <= n; i++)
    {
        f5 = x8 + x88;
        f8 = x5 + x55;
        x55 = x5;
        x88 = x8;

        x5 = f5;
        x8 = f8;
    }
    return x5 + x55 + x8 + x88;
}

int tasks::islandsInMatrix(int ocean[][100], int n)
{
    int islands = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(ocean[i][j])
            {
                islands++;
                walk(i, j, ocean, n);
            }
    return islands;
}

int tasks::SmallBarn::findLeftLength(int i, int j)
{
    int counter = 0;
    while(j < m_N)
    {
        if(m_field[i][j] == 1)
            break;
        counter++;
        j++;
    }
    return counter;
}

void tasks::SmallBarn::findMaxSquare(int i, int j)
{
    int lengthM = 1;
    int limitLength = findLeftLength(i, j);
    int maxSquare = limitLength;
    
    for(int m = i + 1; m < m_M; m++)
    {
        lengthM++;
        int lengthN = findLeftLength(m, j);
        if(lengthN < limitLength)
            limitLength = lengthN;
        else if(lengthN > limitLength)
            lengthN = limitLength;
        if(maxSquare < lengthN * lengthM)
            maxSquare = lengthN * lengthM;
    }
    if(m_maxSquare < maxSquare)
        m_maxSquare = maxSquare;
}


void tasks::SmallBarn::readField()
{
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            std::cin >> m_field[i][j];
}

void tasks::SmallBarn::fillField(int field[][30])
{
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            m_field[i][j] = field[i][j];
}

int tasks::SmallBarn::calc()
{    
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            findMaxSquare(i, j);
    return m_maxSquare;
}
