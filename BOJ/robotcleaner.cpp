#include <cstdio>

int main() {
    int axis[50][50];
    int N, M;
    scanf("%d %d", &N, &M);
    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0 ; i < N ; i++)
        for (int j = 0 ; j < M ; j++)
            scanf("%d", &axis[i][j]);
    int cleanArea = 0;
    int dTemp = 0;
    while(1) {
        if (axis[r][c] == 0) {
            axis[r][c] = 2;
            dTemp = d;
            cleanArea++;
        }
        if (d == 0 && axis[r][c - 1] == 0) { c--; d = 3; continue; }
        else if (d == 1 && axis[r - 1][c] == 0) { r--; d = 0; continue; }
        else if (d == 2 && axis[r][c + 1] == 0) { c++; d = 1; continue; }
        else if (d == 3 && axis[r + 1][c] == 0) { r++; d = 2; continue; }
        if (d == 0) d = 3;
        else if (d == 1) d = 0;
        else if (d == 2) d = 1;
        else if (d == 3) d = 2;
        if (d == dTemp && axis[r][c - 1] >= 1 && axis[r][c + 1] >= 1 && axis[r - 1][c] >= 1 && axis[r + 1][c] >= 1) {
            if (axis[r + 1][c] == 2 && d == 0) { r++; continue; }
            else if (axis[r + 1][c] == 1 && d == 0) break;
            if (axis[r][c - 1] == 2 && d == 1) { c--; continue; }
            else if (axis[r][c - 1] == 1 && d == 1) break;
            if (axis[r - 1][c] == 2 && d == 2) { r--; continue; }
            else if (axis[r - 1][c] == 1 && d == 2) break;
            if (axis[r][c + 1] == 2 && d == 3) { c++; continue; }
            else if (axis[r][c + 1] == 1 && d == 3) break;
        }
    }
    printf("%d\n", cleanArea);

    return 0;
}
