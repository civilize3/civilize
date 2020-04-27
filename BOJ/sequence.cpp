#include <cstdio>

int main() {
    int max = -99999999;
    int N, K;
    int seq[100000] = {0};
    scanf("%d %d", &N, &K);
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &seq[i]);
    int temp = 0;
    for (int i = 0 ; i < K ; i++)
        temp += seq[i];
    if (temp > max) max = temp;
    for (int i = 0 ; i < N - K ; i++) {
        temp = temp - seq[i] + seq[K + i];
        if (temp > max) max = temp;
    }
    printf("%d\n", max);

    return 0;
}
