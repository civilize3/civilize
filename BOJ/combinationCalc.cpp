#include <stdio.h>
using namespace std;

int division(int x, int input[], int res_size)
{
    int res[1000] = {0};
    int idx = res_size - 1;
    int temp = input[idx];
    while(temp < x) temp = temp * 10 + (input[--idx]);
    while(res_size > res_size - idx - 1) {
        for (int i = 999 ; i > 0 ; i--) res[i] = res[i - 1];
        res[0] = (temp / x);
        temp = (temp % x) * 10 + input[--idx];
    }
    int sz = 0;
    for (int i = 999 ; i >= 0 ; i--) {
        if (res[i] > 0) {
            sz = i + 1;
            break;
        }
    }
    for (int i = 0 ; i < 1000; i++) input[i] = res[i];
    return sz;
}

int multiply(int x, int res[], int res_size) 
{ 
    int carry = 0;
  
    for (int i = 0; i < res_size; i++) { 
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod / 10;
    } 
    while (carry) { 
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    } 
    return res_size; 
} 

int multiplyft(int from, int to, int digit[]) {
    digit[0] = from % 10;
    digit[1] = int(from / 10) % 10;
    digit[2] = int(from / 100);
    int res_size;
    if (1 <= from && from < 10) res_size = 1;
    else if (10 <= from && from < 100) res_size = 2;
    else res_size = 3;

    for (int i = from - 1 ; i > to ; i--) res_size = multiply(i, digit, res_size);
    return res_size;
}

int main() {
    int digit[1000] = {0};
    for(int i = 0 ; i < 1000 ; i++) digit[i] = 0;
    int n, m;
    int res_size;
    scanf("%d", &n);
    scanf("%d", &m);
    if (n == m) printf("1\n");
    else {
        m = m > n - m ? m : n - m;
        res_size = multiplyft(n, m, digit);
        for (int i = n - m ; i > 1 ; i--) res_size = division(i, digit ,res_size);
        for (int i = res_size - 1 ; i >= 0; i--) printf("%d",digit[i]);
        printf("\n");
    }

    return 0;
}
