#include <iostream>
#include <vector>
using namespace std;

class BadNeighbors {
private:
    int halfDonations(vector<int> donations);
public:
    int maxDonations(vector<int> donations);
};

int BadNeighbors::maxDonations(vector<int> donations) {
    vector<int> initZero(donations.begin(), donations.end() - 1);
    vector<int> initOne(donations.begin() + 1, donations.end());

    return max(halfDonations(initZero), halfDonations(initOne));
}
int BadNeighbors::halfDonations(vector<int> donations) {
    int localMax[donations.size()] = {0};
    for (int i = 0 ; i < donations.size() ; i++) {
        if (i == 0 || i == 1) localMax[i] = donations[i];
        else if (i == 2) localMax[i] = localMax[i - 2] + donations[i];
        else localMax[i] = max(localMax[i - 3], localMax[i - 2]) + donations[i];
    }
    return localMax[donations.size() - 1];
}

