#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class CirclesCountry {
public:
    int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2);
};

int CirclesCountry::leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2) {
    int totalCrossed = 0;
    for (int i = 0 ; i < R.size() ; i++) {
        int pointInclude = 0;
        if (pow(X[i] - x1, 2) + pow(Y[i] - y1, 2) < pow(R[i], 2)) pointInclude++;
        if (pow(X[i] - x2, 2) + pow(Y[i] - y2, 2) < pow(R[i], 2)) pointInclude++;
        if (pointInclude == 1) totalCrossed++;
    }

    return totalCrossed;
}
