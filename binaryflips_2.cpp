#include <iostream>
#define ITER(i, a, b) for (i = a ; i <= b ; i++)

using namespace std;

class BinaryFlips{
public:
    int minimumMoves(int A, int B, int K);
};

int BinaryFlips::minimumMoves(int A, int B, int K) {
    int i = 0;
    ITER(i, 0, A + B) {
        long long rest = i * K - A;
        long long use = ((i - 1) / 2 * A + i / 2 * B) * 2;
        if (rest >= 0 && rest % 2 == 0 && rest <= use)
            return int(i);
    }

    return -1;
}

