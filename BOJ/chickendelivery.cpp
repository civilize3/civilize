#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > comb;

void combination(vector<int> chicken, vector<int> data, int start, int end, int index, int r) {
    if (index == r) {
        comb.push_back(data);
        return;
    }
    for (int i = start ; i <= end && end - i + 1 >= r - index ; i++) {
        data[index] = chicken[i];
        combination(chicken, data, i + 1, end, index + 1, r);
    }
}

int distance(int r1, int c1, int r2, int c2) {
    int distX = r1 < r2 ? r2 - r1 : r1 - r2;
    int distY = c1 < c2 ? c2 - c1 : c1 - c2;

    return distX + distY;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int axis[50][50] = {0};
    vector<int> house;
    vector<int> chicken;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &axis[i][j]);
            if (axis[i][j] == 1) house.push_back(i * N + j);
            if (axis[i][j] == 2) chicken.push_back(i * N + j);
        }
    }
    vector<int> selected;
    int minDist = 99999999;
    for (int i = 0 ; i < M ; i++)
        selected.push_back(i + 1);
        combination(chicken, selected, 0, chicken.size() - 1, 0, M);
    
        for (int a = 0 ; a < comb.size() ; a++) { 
            int chickenDist = 0;
            for (int i = 0 ; i < house.size() ; i++) {
                int distTemp = 100;
                for (int j = 0 ; j < comb[a].size() ; j++) {
                    if (distTemp > distance(house[i] / N, house[i] % N, comb[a][j] / N, comb[a][j] % N))
                        distTemp = distance(house[i] / N, house[i] % N, comb[a][j] / N, comb[a][j] % N);
                }
            chickenDist += distTemp;
        }
        if (minDist > chickenDist) minDist = chickenDist;
    }
    printf("%d\n", minDist);

    return 0;
}
