#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    char name[21];
    char maxName[21];
    int maxValue = 0;
    int sum = 0;
    int k, m;
    for (int i = 0 ; i < N ; i++) {
        scanf("%s", name);
        scanf("%d %d", &k, &m);
        if (i == 0) {
            for (int j = 0 ; j < 21 ; j++)
                maxName[j] = name[j];
        }
        int maxTemp = k > m ? 0 : 1 + (m - k) / (k - 2);
        if (maxValue < maxTemp) {
            maxValue = maxTemp;
            for (int j = 0 ; j < 21 ; j++)
                maxName[j] = name[j];
        }
        sum += maxTemp;
    }
    printf("%d\n", sum);
    printf("%s\n", maxName);

    return 0;
}
