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
    if (A == 0) return 0;
    if (A + B < K) return -1;
    int dp[A + B + 1];
    for (int i = 0 ; i < 100000 ; i++) dp[i] = -1;
    possibleMoves.push(A);
    dp[A] = 0;

    while(!possibleMoves.empty()) {
        int A_ = possibleMoves.front();
        possibleMoves.pop();
        for (int i = max(0, K - (A + B - A_)) ; i <= min(A_, K) ; i++) {
            int nextzero = A_ + (K - 2 * i);
            if (dp[nextzero] == -1) {
                if (nextzero == 0) return dp[A_] + 1;
                dp[nextzero] = dp[A_] + 1;
                possibleMoves.push(nextzero);
            }
        }
    }
    return -1;
}

int main() {
    BinaryFlips bf;
    //cout << bf.minimumMoves(8000,12000,19999) << endl;
    //cout << bf.minimumMoves(7822,0,1) << endl;
    //cout << bf.minimumMoves(11,99995,99999) << endl; //14285
    cout << bf.minimumMoves(100000,0,99999) << endl; //100000
    //cout << bf.minimumMoves(11,6662,6671) << endl;

    return 0;
}
