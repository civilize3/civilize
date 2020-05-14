#include <cstdio>
#include <math.h>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    int x_irr = 0;
    int y_irr = 0;
    scanf("%d %d", &x, &y);
    string dirName[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
    int dirx[8] = {0, 0, 1, 0, 0, 0, -1, 0};
    int diry[8] = {1, 0, 0, 0, -1, 0, 0, 0};
    int dirx_irr[8] = {0, 1, 0, 1, 0, -1, 0, -1};
    int diry_irr[8] = {0, 1, 0, -1, 0, -1, 0, 1};

    for (int i = 1 ; i < n ; i++) {
        char direction[2] = "";
        int d;
        scanf("%s %d", direction, &d);
        string dir = direction;
        for (int j = 0 ; j < 8 ; j++)
            if (dir == dirName[j]) { x += dirx[j] * d; y += diry[j] * d; x_irr += dirx_irr[j] * d; y_irr += diry_irr[j] * d; break; }
    }
    printf("%.15lf %.15lf\n", double(x) + double(x_irr / sqrt(2)), double(y) + double(y_irr / sqrt(2)));

    return 0;
}
