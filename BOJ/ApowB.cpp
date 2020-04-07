#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    string a;
    int aArray[15];
    int b;
    int bigInteger[1500];
    int bigIntegerTemp[1500];

    cin >> a;
    scanf("%d", &b);
    for (int i = 1499 ; i >= 0 ; i--) { bigInteger[i] = 0; bigIntegerTemp[i] = 0; }
    for (int i = 14 ; i >= 0 ; i--) aArray[i] = 0;
    int dot = 0;
    int dotPos = 0;
    for (int i = 0 ; i < a.length() ; i++) {
        if (a[i] == '.') { dot++; dotPos = a.length() - i - 1;  continue; }
        aArray[a.length() - i - 2 + dot] = a[i] - '0';
    }
    for (int i = 14 ; i >= 0 ; i--) bigInteger[i] = aArray[i];

    for (int m = 0 ; m < b - 1 ; m++) {
        for (int i = 0 ; i < 1485 ; i++) {
            for (int j = 0 ; j < 15 ; j++) {
                bigIntegerTemp[i + j] += bigInteger[i] * aArray[j];
            }
        }
        for (int i = 1499 ; i >= 0 ; i--) { bigInteger[i] = bigIntegerTemp[i]; bigIntegerTemp[i] = 0; }
        for (int i = 0 ; i < 1499 ; i++) 
            if (bigInteger[i] > 9) { bigInteger[i + 1] += bigInteger[i] / 10; bigInteger[i] = bigInteger[i] % 10; }
    }
    
    if (atof(a.c_str()) < 1) {
        for (int i = b * dotPos ; i >= 0 ; i--) {
            printf("%d", bigInteger[i]);
            if (i == b * (dotPos)) printf(".");
        }
    }
    else {
        bool isNotZero = false;
        for (int i = 1499 ; i >= 0 ; i--) {
            if (bigInteger[i] != 0) isNotZero = true;
            if (isNotZero) printf("%d", bigInteger[i]);
            if (i == b * (dotPos)) printf(".");
        }
    }
    printf("\n");

    return 0;
}
