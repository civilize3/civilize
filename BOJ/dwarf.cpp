#include <cstdio>

bool g_isOnce = false;

void swap(int* src, int* target) {
    int temp;
    temp = *target;
    *target = *src;
    *src = temp;
}

void qsort(int dwarfResult[], int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int i = pivot + 1;
    int j = end;

    while(i <= j) {
        while(i <= end && dwarfResult[i] <= dwarfResult[pivot]) i++;
        while(j > start && dwarfResult[j] >= dwarfResult[pivot]) j--;
        if (i > j) swap(dwarfResult + j, dwarfResult + pivot);
        else swap(dwarfResult + i, dwarfResult + j);
    }

    qsort(dwarfResult, start, j - 1);
    qsort(dwarfResult, j + 1, end);
}

void combination(int dwarfResult[7], int dwarf[9], int start, int end, int index, int r) {
    if (index == r) {
        int sum = 0;
        for (int i = 0 ; i < 7 ; i++) sum += dwarfResult[i];
        if (sum == 100 && !g_isOnce) {
            qsort(dwarfResult, 0, 6);
            for (int j = 0 ; j < 7 ; j++) printf("%d\n", dwarfResult[j]);
            g_isOnce = true;
            return;
        }
    }
    for (int i = start ; i <= end && end - i + 1 >= r - index ; i++) {
        dwarfResult[index] = dwarf[i];
        combination(dwarfResult, dwarf, i + 1, end, index + 1, r);
    }
}

int main() {
    int dwarf[9];
    int dwarfResult[7];
    for (int i = 0 ; i < 9 ; i++) scanf("%d", &dwarf[i]);
    combination(dwarfResult, dwarf, 0, 8, 0, 7);
    
    return 0;
}
