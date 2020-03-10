#include <iostream>
#include <queue>
using namespace std;

class BinaryFlips{
public:
    int minimumMoves(int A, int B, int K);
private:
    queue<int> possibleMoves;
};

int BinaryFlips::minimumMoves(int A, int B, int K) {
    int dp[300000];
    for (int i = 0 ; i < 100000 ; i++) dp[i] = -1;

    possibleMoves.push(A);
    dp[A] = 0;

    while(!possibleMoves.empty()) {
        int A_ = possibleMoves.front();
        int B_ = A + B - A_;
        if (A_ % K == 0) return int(A_ / K) + dp[A_];
        possibleMoves.pop();
        for (int i = 0 ; i < K ; i++) {
            if (i > B_ || K - i > A_ || A_ - K + 2 * i >= 100000 || A_ - K + 2 * i < 0  || dp[A_ - K + 2 * i] > -1) continue;
            dp[A_ - K + 2 * i] = dp[A_] + 1;
            possibleMoves.push(A_ - K + 2 * i);
        }
        for (int i = K ; i >= 0 ; i--) {
            if (i > A_ || K - i > B_  || A_ + K - 2 * i >= 100000 || A_ + K - 2 * i < 0  || dp[A_ + K - 2 * i] > -1) continue;
            dp[A_ + K - 2 * i] = dp[A_] + 1;
            possibleMoves.push(A_ + K - 2 * i);
        }
    }
    return dp[0];
}

int main() {
    BinaryFlips bf;
    //cout << bf.minimumMoves(100000,100000,578) << endl;

    //cout << bf.minimumMoves(8000,12000,19999) << endl;
    //cout << bf.minimumMoves(7822,0,1) << endl;
    cout << bf.minimumMoves(11,99995,99999) << endl; //14285
    //cout << bf.minimumMoves(100000,0,99999) << endl; //100000
    //cout << bf.minimumMoves(11,6662,6671) << endl;

    return 0;
}
