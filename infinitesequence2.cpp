#include <iostream>
#include <map>
using namespace std;

class InfiniteSequence2 {
public:
    long calc(long n, int p, int q, int x, int y);
private:
    map<int, long> m_dp;
};

long InfiniteSequence2::calc(long n, int p, int q, int x, int y) {
    if (n <= 0) return 1;
    if (m_dp.count(n) > 0) return m_dp[n];
    else {
        m_dp[n] = calc(long(n/p) - x, p, q, x, y) + calc(long(n/q) - y, p, q, x, y);
        return m_dp[n];
    }
    return 0;
}

