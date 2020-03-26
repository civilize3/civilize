#include <stdio.h>

int main() {
    long long A, B, V;
    scanf("%lld", &A);
    scanf("%lld", &B);
    scanf("%lld", &V);

    printf("%lld\n", ((V - A)%(A - B) == 0 ? (long long)((V - A) / (A - B)) + 1 : (long long)((V - A) / (A - B)) + 2));

    return 0;
}
