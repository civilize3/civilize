#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int M, N, K;
    cin >> M;
    cin >> N;
    cin >> K;
    int field[M][N];
    for (int m = 0 ; m < M ; m++)
        for (int n = 0 ; n < N ; n++)
            field[m][n] = 0;
    for (int i = 0 ; i < K ; i++) {
        int x1,x2,y1,y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        for (int m = y1 ; m < y2 ; m++)
            for (int n = x1 ; n < x2 ; n++)
                field[m][n] = 1;
    }
    
    queue<pair<int,int> > axis;
    vector<int> areas;
    
    for (int m = 0 ; m < M ; m++) {
        for (int n = 0 ; n < N ; n++) {
            if (field[m][n] == 0) {
                int area = 0;
                axis.push(make_pair(m, n));
                while(!axis.empty()) {
                    int mm = axis.front().first;
                    int nn = axis.front().second;
                    field[mm][nn] = 1;
                    if (field[mm][nn - 1] == 0 && nn - 1 >= 0) { field[mm][nn - 1] = 1; axis.push(make_pair(mm, nn - 1)); }
                    if (field[mm][nn + 1] == 0 && nn + 1 < N) { field[mm][nn + 1] = 1; axis.push(make_pair(mm, nn + 1)); }
                    if (field[mm - 1][nn] == 0 && mm - 1 >= 0) { field[mm - 1][nn] = 1; axis.push(make_pair(mm - 1, nn)); }
                    if (field[mm + 1][nn] == 0 && mm + 1 < M) { field[mm + 1][nn] = 1; axis.push(make_pair(mm + 1, nn)); }
                    area++;
                    axis.pop();
                }
                areas.push_back(area);
            }
        }   
    }
    sort(areas.begin(), areas.end());
    printf("%d\n", int(areas.size()));
    for (int i = 0 ; i < areas.size() ; i++) printf("%d ", areas[i]);
    printf("\n");
    
    return 0;
}
