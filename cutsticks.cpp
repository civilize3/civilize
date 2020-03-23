#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CutSticks {
public:
    double maxKth(vector<int> sticks, int C, int K);
};

double CutSticks::maxKth(vector<int> sticks, int C, int K) {
    double Max = 1000000000;
    double Min = 1;
    double mid = (Max + Min) / 2.0;
    
    while (Max - Min > 0.000001) {
        long long count = 0;
        long long numCuts = 0;
        for (unsigned i = 0 ; i < sticks.size() ; i++) {
            count += int(sticks[i] / mid);
            if (int(sticks[i] / mid) >= 1) numCuts += int(sticks[i] / mid) - 1;
        }
        if (numCuts - C > 0) count -= (numCuts - C);
        if (count >= K) Min = mid;
        else Max = mid;
        mid = (Max + Min) / 2.0;
    }
    return mid;    
}