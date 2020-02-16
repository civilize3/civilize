#include <iostream>
using namespace std;

class HandsShaking {
public:
    long countPerfect(int n);
};

long HandsShaking::countPerfect(int n)
{
    long dp[50] = {0};
    
    for(int i = 2 ; i <= n ; i += 2) {
        if (i == 2) 
            dp[i] = 1;
        else {
            dp[i] = 2 * dp[i - 2];
            for (int j = 0 ; j < (i / 2) - 2 ; j++)
                dp[i] += dp[2 * (j + 1)] * dp[i - 4 - 2 * j];
        }
    }
    return dp[n];
}
