#include <cstdio>

int numNines(int input) {
    int res = 0;
    while(input != 0) {
        if (input % 10 == 9) res++;
        input /= 10;
    }
    return res;
}

int main() {
    int bingo[500][500] = {0};
    int n, m;
    int count = 0;
    int lineMax = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        int lineTemp = 0;
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &bingo[i][j]);
            bingo[i][j] = numNines(bingo[i][j]);
            count += bingo[i][j];
            lineTemp += bingo[i][j];
        }
        if (lineTemp > lineMax) lineMax = lineTemp;
    }
    for (int j = 0 ; j < m ; j++) {
        int lineTemp = 0;
        for (int i = 0 ; i < n ; i++)
            lineTemp += bingo[i][j];
        if (lineTemp > lineMax) lineMax = lineTemp;
    }

    printf("%d\n", count - lineMax);

    return 0;
}
