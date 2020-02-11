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
    int dp[donations.size()] = {0};
    int sum = 0;
    for(int i = 0 ; i < donations.size() ; i++) {
        dp[i] = donations[i];
        if(i > 0) dp[i] = max(dp[i], dp[i - 1]);
        if(i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i]);
        sum = max(dp[i], sum);
    }
    return sum;
}

