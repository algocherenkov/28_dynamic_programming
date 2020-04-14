#include "task_solutions.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <stack>
namespace tasks {

/*******************************************ONETWOPEAS*********************************************/
OneTwoPeas::FractionsData tasks::OneTwoPeas::parseData()
{
    m_data.erase(std::remove(m_data.begin(), m_data.end(), ' '), m_data.end());
    FractionsData result;

    auto divPos = m_data.find_first_of('/');
    if(divPos == std::string::npos)
    {
        std::cerr << "wrong input. No 'division' sign" << std::endl;
        return FractionsData{-1, -1, -1, -1};
    }

    auto a_str = m_data.substr(0, divPos);
    result.a = atoi(a_str.c_str());

    auto signPos = m_data.find_first_of("+-", divPos);
    if(signPos == std::string::npos)
    {
        std::cerr << "wrong input.No 'operator' sign" << std::endl;
        return FractionsData{-1, -1, -1, -1};
    }

    auto b_str = m_data.substr(divPos + 1, signPos - divPos - 1);
    result.b = atoi(b_str.c_str());

    auto divPos2 = m_data.find_first_of('/', signPos);
    if(divPos2 == std::string::npos)
    {
        std::cerr << "wrong input. No 'division' sign" << std::endl;
        return FractionsData{-1, -1, -1, -1};
    }

    auto c_str = m_data.substr(signPos, divPos2);
    result.c = atoi(c_str.c_str());

    auto d_str = m_data.substr(divPos2 + 1);
    result.d = atoi(d_str.c_str());

    return result;
}

int OneTwoPeas::gcd(int x, int y)
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

std::pair<int, int> OneTwoPeas::calc()
{
    auto data = parseData();
    int x = data.a * data.d + data.b * data.c;
    int y = data.b * data.d;

    int g = gcd(x, y);
    x /= g;
    y /= g;

    return std::pair<int,int>(x,y);
}

/*******************************************FURTREEGARLAND*********************************************/
int furTreeGarlandValue(int tree[][100], int height)
{
    for(int i = height - 2; i >= 0 ; i--)
        for(int j = 0; j <= i; j++)
            tree[i][j] += std::max(tree[i + 1][j], tree[i + 1][j + 1]);
    return tree[0][0];
}

/*******************************************FIVEONEIGHT*********************************************/
int fiveOnEight(int n)
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

/*******************************************ISLANDSINMATRIX*********************************************/
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

int islandsInMatrix(int ocean[][100], int n)
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

/*******************************************SMALLBARN*********************************************/
int BarnFinder::findLeftLength(int i, int j)
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

void BarnFinder::findMaxSquare(int i, int j)
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


void BarnFinder::readField()
{
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            std::cin >> m_field[i][j];
}

void BarnFinder::fillField(int field[][30])
{
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            m_field[i][j] = field[i][j];
}

int BarnFinder::calcWithBruteForce()
{    
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            findMaxSquare(i, j);
    return m_maxSquare;
}

void BarnFinder::readTreeCoords()
{
    int x = 0;
    int y = 0;
    int t = 0;
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        std::cin >> x;
        std::cin >> y;

        m_treeCoords.emplace(x, y);
    }
}

void BarnFinder::fillTreeCoords(int coords[2][30], int t)
{
    for(int i = 0; i < t; i++)
        m_treeCoords.emplace(coords[i][0], coords[i][1]);
}

void BarnFinder::calcMatrixLengthsAboveCells()
{
    for(int i = 0; i < m_M; i++)
        findMaxSquareAboveCell(i);
}

void BarnFinder::printMatrixLengthsAboveCells()
{
    for(int i = 0; i < m_M; i++)
    {
        for(int j = 0; j < m_N - 1; j++)
            std::cout << m_matrixLengthsAboveCells[i][j] << " ";
        std::cout << m_matrixLengthsAboveCells[i][m_N - 1] << std::endl;
    }
}

void BarnFinder::getMatrixLengthsAboveCells(int field[][30])
{
    for(int i = 0; i < m_M; i++)
        for(int j = 0; j < m_N; j++)
            field[i][j] = m_matrixLengthsAboveCells[i][j];
}

void BarnFinder::readBuff()
{
    int length = 0;
    std::cin >> length;
    for(int i = 0; i < length; i++)
        std::cin >> m_buffLine[i];
}

void BarnFinder::fillBuff(int line[], int length)
{
    for(int i = 0; i < length; i++)
        m_buffLine[i] = line[i];
}

void BarnFinder::calcLRBuffs()
{
    std::stack<int> store;

    for(int i = m_N - 1; i >= 0; i--)
    {
        if(!m_buffLine[i])
            m_buffL[i] = i;
        else if(i > 0 && m_buffLine[i] <= m_buffLine[i - 1])
            store.push(i);
        else if(!store.empty())
        {
            store.push(i);
            int border = store.top();
            if(i > 0)
                for(int k = i; m_buffLine[k] > m_buffLine[i - 1]; k++)
                {
                    if(m_buffL[k])
                        continue;
                    m_buffL[k] = border;
                    store.pop();
                }
            else if(!store.empty())
            {
                while(!store.empty())
                {
                    m_buffL[store.top()] = border;
                    store.pop();
                }
            }
        }
    }

    for(int i = 0; i < m_N; i++)
    {
        if(!m_buffLine[i])
            m_buffR[i] = i;
        else if(i < (m_N - 1) && m_buffLine[i] <= m_buffLine[i + 1])
            store.push(i);
        else if(!store.empty())
        {
            store.push(i);
            int border = store.top();
            if(i < (m_N - 1))
                for(int k = i; m_buffLine[k] > m_buffLine[i + 1]; k--)
                {
                    if(m_buffR[k])
                        continue;
                    m_buffR[k] = border;
                    store.pop();
                }
            else if(!store.empty())
            {
                while(!store.empty())
                {
                    m_buffR[store.top()] = border;
                    store.pop();
                }
            }
        }
    }
}

void BarnFinder::printLRBuffs()
{
    for(int i = 0; i < m_N - 1; i++)
    {
        std::cout << m_buffL[i] << " ";
    }
    std::cout << m_buffL[m_N - 1] << std::endl;

    for(int i = 0; i < m_N - 1; i++)
    {
        std::cout << m_buffR[i] << " ";
    }
    std::cout << m_buffR[m_N - 1];
}

void BarnFinder::findMaxSquareAboveCell(int i)
{    
    for(int j = 0; j < m_N; j++)
    {
        if(m_treeCoords.count(std::pair<int, int>(j, i)))
            m_matrixLengthsAboveCells[i][j] = 0;
        else
            m_matrixLengthsAboveCells[i][j]++;
    }
    for(int k = 0; k < m_N; k++)
        m_matrixLengthsAboveCells[i + 1][k] = m_matrixLengthsAboveCells[i][k];    
}
}
