#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T;
    queue<int> axisRow;
    queue<int> axisCol;
    vector<int> countVec;
    scanf("%d", &T);
    bool field[50][50];
    for (int m = 0 ; m < 50 ; m++)
        for (int n = 0 ; n < 50 ; n++)
            field[m][n] = false;
    int M, N, K;
    for (int i = 0 ; i < T ; i++) {
        scanf("%d %d %d", &M, &N, &K);
        for (int j = 0 ; j < K ; j++) {
            int row, col;
            scanf("%d %d", &row, &col);
            field[row][col] = true;
        }
        int count = 0;
        for (int m = 0 ; m < M ; m++) {
            for (int n = 0 ; n < N ; n++) {
                if(field[m][n]) { axisRow.push(m); axisCol.push(n); count++; }
                while (!axisRow.empty()) {
                    int row = axisRow.front();
                    int col = axisCol.front();
                    field[row][col] = false;
                    if (row + 1 < M && field[row + 1][col]) { field[row + 1][col] = false; axisRow.push(row + 1); axisCol.push(col); }
                    if (0 <= row - 1 && field[row - 1][col]) { field[row - 1][col] = false; axisRow.push(row - 1); axisCol.push(col); }
                    if (col + 1 < N && field[row][col + 1]) { field[row][col + 1] = false; axisRow.push(row); axisCol.push(col + 1); }
                    if (0 <= col - 1 && field[row][col - 1]) { field[row][col - 1] = false; axisRow.push(row); axisCol.push(col - 1); }
                    axisRow.pop();
                    axisCol.pop();
                }
            }
        }
        countVec.push_back(count);
    }
    for (int i = 0 ; i < T ; i++) {
        printf("%d\n", countVec[i]);
    }

    return 0;
}
