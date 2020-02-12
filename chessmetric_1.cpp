#include <iostream>
#include <vector>
using namespace std;

class ChessMetric{
private:
    long long movable(int x, int y, int size, long long *dp);
public:
    long long howMany(int size, vector<int> start, vector<int> end, int numMoves);
};

long long ChessMetric::howMany(int size, vector<int> start, vector<int> end, int numMoves) {
    long long dp[size][size];
    long long dpNew[size][size];
    for (int i = 0 ; i < size ; i++)
        for (int j = 0 ; j < size ; j++)
            dp[i][j] = 0;
    dp[start[0]][start[1]] = 1;
            
    for (int move = 0 ; move < numMoves ; move++) {
        for (int i = 0 ; i < size ; i++) {
            for (int j = 0 ; j < size ; j++) {
                dpNew[i][j] = 0;
                dpNew[i][j] = movable(j + 1, i, size, *dp) +  movable(j + 1, i, size, *dp) +  movable(j, i + 1, size, *dp) +  movable(j, i - 1, size, *dp)
                            + movable(j + 1, i + 1, size, *dp) +  movable(j + 1, i - 1, size, *dp) +  movable(j - 1, i + 1, size, *dp) +  movable(j - 1, i - 1, size, *dp)
                            + movable(j + 1, i + 2, size, *dp) +  movable(j + 1, i - 2, size, *dp) +  movable(j - 2, i + 1, size, *dp) +  movable(j - 2, i - 1, size, *dp)
                            + movable(j + 2, i + 1, size, *dp) +  movable(j + 2, i - 1, size, *dp) +  movable(j - 1, i + 2, size, *dp) +  movable(j - 1, i - 2, size, *dp);
            }
        }
        for (int i = 0 ; i < size ; i++)
            for (int j = 0 ; j < size ; j++)
                dp[i][j] = dpNew[i][j];
    }
    return dp[end[0]][end[1]];
}

long long ChessMetric::movable(int x, int y, int size, long long *dp) {
    if (x < 0 || size <= x || y < 0 || size <= y)
        return 0;
    return *(dp + x * size + y);
}