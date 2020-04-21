#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    vector<int> result;
    int N;
    for (int i = 0 ; i < T ; i++) {
        scanf("%d", &N);
        int test;
        int resultEqual = 0;
        for (int j = 0 ; j < N ; j++) {
            scanf("%d", &test);
            if (test == j + 1) resultEqual++;
        }
        result.push_back(resultEqual);
    }
    for (int i = 0 ; i < T ; i++)
        printf("%d\n", result[i]);

    return 0;
}
