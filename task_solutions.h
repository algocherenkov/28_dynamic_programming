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

    constexpr int MAX_SIZE = 30;
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
        int calcWithBruteForce();
        //for test purposes
        void fillField(int field[30][30]);

        //for 1st part of barn task
        void readTreeCoords();
        void calcRowWithLengthsAboveCells(); //Matrix will be calc too
        void printMatrixLengthsAboveCells();
        //for test purposes
        void fillTreeCoords(int[2][30], int t);
        void getMatrixLengthsAboveCells(int field[30][30]);

        //2nd part of barn task
        void readBuff();
        void calcLRBuffs(int* row);
        void printLRBuffs();
        
        //for test purposes
        int* getLBuff() { return m_buffL; }
        int* getRBuff() { return m_buffR; }
        void clearBuffs() { memset(m_buffL, 0, m_N * sizeof(int)); memset(m_buffR, 0, m_N * sizeof(int)); }

        //3rd part of barn task
        int calcMaxSquare();

    private:
        int findLeftLength(int i, int j);
        void findMaxSquare(int i, int j);
        void findMaxSquareAboveCell(int i);
        int findMaxSquareOnLine();
    private:
        int m_M{0};
        int m_N{0};

        int m_field[MAX_SIZE][MAX_SIZE];
        int m_maxSquare{0};

        std::unordered_set<std::pair<int, int>, pair_hash> m_treeCoords;
        int m_rowWithLengthsAboveCells[MAX_SIZE]{0};

        //for test purposes
        int m_matrixWithLengthsAboveCells[MAX_SIZE][MAX_SIZE]{{0}};
        bool m_buffWasConsoleRead{ false };

        int m_buffLine[MAX_SIZE]{0};
        int m_buffL[MAX_SIZE]{0};
        int m_buffR[MAX_SIZE]{0};
    };    
}
