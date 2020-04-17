#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    int criteria = 10;
    int digit = 1;
    while(N > criteria) {
        criteria = criteria * 10 + 10;
        digit++;
    }
    printf("%d\n",digit);

    return 0;
}
