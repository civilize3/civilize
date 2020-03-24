#include <stdio.h>
#include <vector>
using namespace std;

void combinationUtil(vector<int> dice, int data[], int start, int end, int index, int r) {
    if (index == r) {
        for (int i = 0 ; i < r ; i++)
            printf("%d", data[i]);
        printf("\n");
        return;
    }
    for (int i = start ; i <= end && end - i + 1 >= r - index ; i++) {
        data[index] = dice[i];
        combinationUtil(dice, data, i + 1, end, index + 1, r);
    }
}

void printCombination(vector<int> dice, int r) {
    int data[r];
    combinationUtil(dice, data, 0, dice.size() - 1, 0, r);
}

int main() {
// print all combination 6 dices
    int d[6] = {1,2,3,4,5,6};
    vector<int> dice(d, d + sizeof(d) / sizeof(int));
    int r = 3;
    printCombination(dice, r);

    return 0;
}
