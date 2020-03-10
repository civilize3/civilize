#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class BinaryFlips{
public:
    int minimumMoves(int A, int B, int K);
private:
    int array[300000];
    int k;
    queue<int> possibleMoves;
    void check(int nowzero, int usezero);
};

int BinaryFlips::minimumMoves(int A, int B, int K) {
    if (A == 0) return 0;
    if (A + B == K) return -1;
    k = K;
    for (int i = 0 ; i < A + B ; i++) array[i] = -1;
    possibleMoves.push(A);
    array[A] = 0;

    while(!possibleMoves.empty()) {
        int i = possibleMoves.front();
        possibleMoves.pop();
        check(i, max(0, K - (A + B - i)));
        check(i, min(i, K));
        check(i, min(max((i + 1) / 2, K - (A + B - i)),K));
        check(i, min(max(i / 2, K - (A + B - i)),K));
    }
    return array[0];
}

void BinaryFlips::check(int nowzero, int usezero) {
    int nextzero = nowzero + k - 2 * usezero;
    if (array[nextzero] == -1) {
        array[nextzero] = array[nowzero] + 1;
        possibleMoves.push(nextzero);
    }
}

int main() {
    BinaryFlips bf;
    //cout << bf.minimumMoves(8000,12000,19999) << endl;
    //cout << bf.minimumMoves(7822,0,1) << endl;
    cout << bf.minimumMoves(11,99995,99999) << endl; //14285
    //cout << bf.minimumMoves(100000,0,99999) << endl; //100000
    //cout << bf.minimumMoves(11,6662,6671) << endl;

    return 0;
}
