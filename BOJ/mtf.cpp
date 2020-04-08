#include <cstdio>

int main() {
    int T, n, a;
    scanf("%d", &T);
    char word[T][100];
    int wordlength[T];
    for (int i = 0 ; i < T ; i++) {
        char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
        scanf("%d", &n);
        wordlength[i] = n;
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &a);
            char charTemp = *(alphabet + a);
            char alphabetTemp[26];
            alphabetTemp[0] = charTemp;
            word[i][j] = charTemp;
            for (int x = 0 ; x < a ; x++) alphabetTemp[x + 1] = alphabet[x];
            for (int x = a + 1 ; x < 26 ; x++) alphabetTemp[x] = alphabet[x];
            for (int x = 0 ; x < 26 ; x++) alphabet[x] = alphabetTemp[x];
        }
    }
    for (int i = 0 ; i < T ; i++) {
        for (int j = 0 ; j < wordlength[i] ; j++) {
            printf("%c", word[i][j]);
        }
        printf("\n");
    }
    return 0;
}
