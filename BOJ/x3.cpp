#include <cstdio>

int main() {
    int N;
    int villagers[1000000];
    long long value = 0;
    scanf("%d", &N);
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &villagers[i]);
    for (int i = 19 ; i >= 0 ; i--) {
        int numMoreThan = 0;
        for (int j = 0 ; j < N ; j++) {
            if (villagers[j] >= (1 << i)) { numMoreThan++; villagers[j] -= (1 << i); }
        }
        value += (long long)(N - numMoreThan) * (long long)(numMoreThan) * (long long)(1 << i);
    }
    printf("%lld\n", value);

    return 0;
}
