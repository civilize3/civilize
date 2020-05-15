#include <cstdio>

void writeCost(int* minCost, int* cost, int* customer, int start, int C, int N) {
    for (int i = 0 ; i < N ; i++) {
        if (minCost[start + customer[i]] == 0 || cost[i] + minCost[start] < minCost[start + customer[i]])
        minCost[start + customer[i]] = cost[i] + minCost[start];
    }
    for (int i = start + 1 ; i < C ; i++)
        if (minCost[i] > 0) { writeCost(minCost, cost, customer, i, C, N); break; }
}

int main() {
    int minCost[1111];
    int C, N;
    int customer[20];
    int cost[20];
    scanf("%d %d", &C, &N);
    for (int i = 0 ; i < N ; i++) scanf("%d %d", &cost[i], &customer[i]);
    for (int i = 0 ; i < 1111 ; i++) minCost[i] = 0;
    writeCost(minCost, cost, customer, 0, C, N);
    int totalCost = 99999999;
    for (int i = C ; i < 1111 ; i++)
        if (minCost[i] > 0 && totalCost > minCost[i]) totalCost = minCost[i];
    printf("%d\n", totalCost);

    return 0;
}
