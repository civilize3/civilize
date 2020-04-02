#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> getPi(string target) {
    vector<int> pi;
    unsigned int len = target.length();
    pi.push_back(0);
    for (unsigned int i = 1, m = 0 ; i < len ; i++) {
        while (m > 0 && target[i] != target[m]) m = pi[m - 1];
        if (target[i] == target[m]) ++m;
        pi.push_back(m);
    }
    return pi;
}

int main() {
    string src, target;
    cin >> src >> target;
    vector<int> pi;

    pi = getPi(target);

    for (unsigned int i = 0, m = 0 ; i < src.length() ; i++) {
        while (m > 0 && src[i] != target[m]) m = pi[m - 1];
        if (src[i] == target[m]) ++m;
        if (m >= target.length()) { printf("%d\n", i - m + 1); break; }
        else if (i == src.length() - 1) printf("-1\n");
    }

    return 0;
}
