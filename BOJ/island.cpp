#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int axis[50][50];
    queue<int> qx, qy;
    int nearx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int neary[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
    while(1) {
        qx.empty();
        qy.empty();
        unsigned int count = 0;
        for (int i = 0 ; i < 50 ; i++)
            for (int j = 0 ; j < 50 ; j++)
                axis[i][j] = 0;
        unsigned int w, h;
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;
        for (int i = 0 ; i < h ; i++) {
            for (int j = 0 ; j < w ; j++)
                scanf("%d", &axis[i][j]);
        }
        for (int i = 0 ; i < h ; i++) {
            for (int j = 0 ; j < w ; j++) {
                if (axis[i][j] == 1) { qx.push(j); qy.push(i); count++; }
                while (!qx.size() == 0) {
                    int axisx = qx.front();
                    int axisy = qy.front();
                    qx.pop();
                    qy.pop();
                    axis[axisy][axisx] = 0;
                    for (int k = 0 ; k < 8 ; k++) {
                        if (0 <= axisx + nearx[k] && axisx + nearx[k] < w &&
                        0 <= axisy + neary[k] && axisy + neary[k] < h &&
                        axis[axisy + neary[k]][axisx + nearx[k]] == 1) {
                            axis[axisy + neary[k]][axisx + nearx[k]] = 0; 
                            qx.push(axisx + nearx[k]);
                            qy.push(axisy + neary[k]);
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
