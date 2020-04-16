#include <cstdio>

int countPairings(bool taken[10], bool areFriends[][10], int n) {
    int firstFree = -1;
    for (int i = 0 ; i < n ; ++i)
        if(!taken[i]) { firstFree = i; break; }

    if (firstFree == -1) return 1;
    int ret = 0;
    for (int pairWith = firstFree + 1 ; pairWith < n ; ++pairWith) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken, areFriends, n);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main() {
    int C, n, m;
    scanf("%d", &C);
    int result[50];
    for (int i = 0 ; i < C ; i++) {
        scanf("%d %d", &n, &m);
        bool areFriends[10][10] = {false};
        for (int j = 0 ; j < m ; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > b) areFriends[b][a] = true;
            else areFriends[a][b] = true;
        }
        bool taken[10] = {false};
        result[i] = countPairings(taken, areFriends, n);
    }
    for (int i = 0 ; i < C ; i++) printf("%d\n", result[i]);
    
    return 0;
}
