#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    vector<int> s;
    long long x, y;
    for (int i = 0 ; i < T ; i++) {
        scanf("%lld %lld", &x, &y);
        
        long long c = 2 - (y - x);
        double soln = (-3 + sqrt(9 - 4 * c)) / 2 + 2;
        if ((soln - int(soln)) == 0.0) soln = soln - 1;
        
        long long eq = int(soln) - 2;
        int carry = 0;
        if (y - x - (eq * eq + 3 * eq + 2) <= int(soln)) carry = -1;
        s.push_back(int(soln) * 2 + carry);
    }
    for (int i = 0 ; i < T ; i++) printf("%d\n", s[i]);

    return 0;
}
