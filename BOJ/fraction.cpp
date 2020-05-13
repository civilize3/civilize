#include <cstdio>
#include <math.h>

int main() {
    int X;
    scanf("%d", &X);
    int nth = int((sqrt(1 + 8 * X) - 1) / 2);
    if (((sqrt(1 + 8 * X) - 1) / 2) - nth == 0) nth--;
    int moves = X - (nth * nth + nth) / 2 - 1;
    if (nth % 2 == 0) printf("%d/%d\n", nth - moves + 1, moves + 1);
    else printf("%d/%d\n", moves + 1, nth - moves + 1);

    return 0;
}
