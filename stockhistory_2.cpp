#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

class StockHistory {
public:
    int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices);
private:
    vector<string> split(string str, char delimiter);
};

int StockHistory::maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices) {
    double totalGain = 0;
    double globalMax = 0;
    int investCost = initialInvestment;
    int finalMonthValue[999];
    double investSelect[50] = {-1};
    
    for (int i = stockPrices.size() - 1 ; i >= 0 ; i--) {
        vector<string> result = split(stockPrices[i], ' ');
        double monthlyMax = 0;
        int monthlyMaxStock = -1;
        for (int j = 0 ; j < result.size() ; j++) {
            int resultInteger;
            istringstream(result[j]) >> resultInteger;
            if (i == stockPrices.size() - 1) finalMonthValue[j] = resultInteger;
            else monthlyMax = max(monthlyMax,double(finalMonthValue[j]) / double(resultInteger) - 1);
        }
        if (monthlyMax > globalMax) {
            globalMax = monthlyMax;
            investSelect[i] = globalMax;
        }
    }
    for (int i = 0 ; i < stockPrices.size() ; i++) {
        if (investSelect[i] > 0) {
            totalGain += investCost * investSelect[i];
            investCost = 0;
        }
        investCost += monthlyContribution;
    }
    return int(totalGain);
}

vector<string> StockHistory::split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
   
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

