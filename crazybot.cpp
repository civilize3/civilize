#include <iostream>
using namespace std;

class CrazyBot {
private:
    double m_prob[4];
    bool m_axis[30][30];
    double move(int x, int y, int n);
    int m_moveX[4];
    int m_moveY[4];

public:
    CrazyBot();
    double getProbability(int n, int east, int west, int south, int north);
};

CrazyBot::CrazyBot()
{
    bool axis[30][30] = {{false}};
    int moveX[4] = {1,-1,0,0};
    int moveY[4] = {0,0,-1,1};
    
    for (int i = 0 ; i < sizeof(moveX) / sizeof(moveX[0]) ; i++) {
        m_moveX[i] = moveX[i];
        m_moveY[i] = moveY[i];
    }
    for (int i = 0 ; i < sizeof(axis[0]) / sizeof(axis[0][0]) ; i++)
        for (int j = 0 ; j < sizeof(axis[0]) / sizeof(axis[0][0]) ; j++)
            m_axis[i][j] = axis[i][j];
}

double CrazyBot::getProbability(int n, int east, int west, int south, int north)
{
    m_prob[0] = (double)east / 100;
    m_prob[1] = (double)west / 100;
    m_prob[2] = (double)south / 100;
    m_prob[3] = (double)north / 100;
    
    return move(15,15,n);
}

double CrazyBot::move(int x, int y, int n)
{
    double result;
    if (m_axis[x][y]) return 0.0;
    if (n == 0) return 1.0;
    m_axis[x][y] = true;
    result = 0;
    for (int i = 0 ; i < 4 ; i++)
        result += move(x + m_moveX[i], y + m_moveY[i], n - 1) * m_prob[i];
    m_axis[x][y] = false;
    
    return result;
}
