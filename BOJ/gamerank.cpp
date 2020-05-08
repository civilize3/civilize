#include <cstdio>
#include <string>
using namespace std;

int main() {
    char winlose[10001];
    int rank[26] = {0,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2};
    scanf("%s", winlose);
    string wl(winlose);
    unsigned int currentRank = 25;
    for (int i = 0, stars = 0, seq = 0 ; i < wl.length() ; i++) {
        if (currentRank == 0) break;
        if (wl[i] == 'W') seq++;
        else seq = 0;
        if (seq >= 1) stars++;
        else if (seq == 0 && currentRank <= 20) stars--;
        if (seq >= 3 && currentRank >= 6) stars++;
        if (stars > rank[currentRank]) { stars = stars - rank[currentRank]; currentRank--; }
        else if (stars < 0) {
            if (currentRank < 20) { currentRank++; stars = rank[currentRank] - 1; }
            else stars = 0;
        }
    }
    if (currentRank == 0) printf("Legend\n");
    else printf("%d\n", currentRank);

    return 0;
}
