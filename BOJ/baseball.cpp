#include <stdio.h>

int main () {
    int testcase;
    int Y, K;
    int yonsei, korea;
    scanf("%d", &testcase);

    for (int i = 1 ; i < testcase + 1 ; i++) {
        yonsei = 0;
        korea = 0;
        for (int j = 0 ; j < 9 ; j++) {
            scanf("%d %d", &Y, &K);
            yonsei += Y;
            korea += K;
        }
        if (yonsei > korea) printf("Yonsei");
        else if (yonsei < korea) printf("Korea");
        else printf("Draw");
        printf("\n");
    }
    return 0;
}
