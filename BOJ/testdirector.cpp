#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    int A[1000000];
    for (int i = 0 ; i < N ; i++)
        scanf("%d", &A[i]);
    int B, C;
    scanf("%d %d", &B, &C);
    long long res = N;
    for (int i = 0 ; i < N ; i++) {
        A[i] > B ? A[i] -= B : A[i] = 0;
        res += A[i] % C > 0 ? 1 : 0;
        res += int(A[i] / C);
    }
    printf("%lld\n", res);

    return 0;
}
