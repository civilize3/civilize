#include <stdio.h>

int main () {
    int N, F;
    double F_good, F_bad;
    double nextGood = 0;
    double nextBad = 0;
    double gg, gb, bg, bb;
    scanf("%d %d", &N, &F);
    scanf("%lf %lf %lf %lf", &gg, &gb, &bg, &bb);

    F_good = (F == 0) ? 1 : 0;
    F_bad = (F == 1) ? 1 : 0;

    for (int i = 0 ; i < N ; i++) {
        nextGood = F_good * gg + F_bad * bg;
        nextBad = F_good * gb + F_bad * bb;
        F_good = nextGood;
        F_bad = nextBad;
    }

    printf("%d\n", int(F_good * 1000));
    printf("%d\n", int(F_bad * 1000));

    return 0;
}
