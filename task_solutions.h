#pragma once
#include <string>
#include <unordered_set>
#include <utility>

namespace {
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};
}
namespace tasks {

    class OneTwoPeas
    {
    public:
        OneTwoPeas() = default;
        void readInput();
        void setData(std::string& input) { m_data = input; }

        std::pair<int, int> calc();

    private:
        struct FractionsData {
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
        };

        FractionsData parseData();

        bool even(int x) { return (x & 1) == 0; }
        bool odd(int x) { return (x & 1) == 1; }

        int gcd(int x, int y);

    private:
        std::string m_data;
    };

    int furTreeGarlandValue(int tree[][100], int height);

    int fiveOnEight(int n);

    int islandsInMatrix(int ocean[][100], int n);


    class BarnFinder
    {
    public:
        BarnFinder(int N, int M):
            m_M(M),
            m_N(N)
        {}

        BarnFinder() = default;

        //for small barns
        void readField();
        void fillField(int field[30][30]);
        int calcWithBruteForce();

        //for 1st part of barn task
        void readTreeCoords();
        void fillTreeCoords(int [2][30], int t);
        void calcMatrixLengthsAboveCells();
        void printMatrixLengthsAboveCells();
        void getMatrixLengthsAboveCells(int field[30][30]);

    private:
        int findLeftLength(int i, int j);
        void findMaxSquare(int i, int j);
        void findMaxSquareAboveCell(int i);
    private:
        int m_M{0};
        int m_N{0};
        int m_field[1000][1000];

        std::unordered_set<std::pair<int, int>, pair_hash> m_treeCoords;
        int m_matrixLengthsAboveCells[1000][1000]{{0}};
        int m_maxSquare{0};
    };    
}
