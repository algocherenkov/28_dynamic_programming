#pragma once
#include <string>

namespace tasks {

    std::pair<int, int> oneDivTwoPeas(std::string& input);

    int furTreeGarlandValue(int tree[][100], int height);

    int fiveOnEight(int n);

    int islandsInMatrix(int ocean[][100], int n);


    class SmallBarn
    {
    public:
        SmallBarn(int N, int M):
            m_M(M),
            m_N(N)
        {}

        SmallBarn() = default;

        void readField();
        void fillField(int field[30][30]);
        int calc();

    private:
        int findLeftLength(int i, int j);
        void findMaxSquare(int i, int j);
    private:
        int m_M{0};
        int m_N{0};
        int m_field[30][30];
        int m_maxSquare{0};
    };
}
