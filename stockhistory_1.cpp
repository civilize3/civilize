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
    int m_finalValue[50];
    double m_investSelect[50][999];
};

int StockHistory::maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices) {
    double totalGain = 0;
    double globalMax = 0;
    int investCost = initialInvestment;
    for (int i = 0 ; i < 50 ; i++)
        for (int j = 0 ; j < 999 ; j++)
            m_investSelect[i][j] = -1;
    for (int i = stockPrices.size() - 1 ; i >= 0 ; i--) {
        vector<string> result = split(stockPrices[i], ' ');
        double monthlyMax = 0;
        int monthlyMaxStock = -1;
        for (int j = 0 ; j < result.size() ; j++) {
            int resultInteger;
            istringstream(result[j]) >> resultInteger;
            if (i == stockPrices.size() - 1) m_finalValue[j] = resultInteger;
            else {
                if (double(m_finalValue[j]) / double(resultInteger) - 1 > monthlyMax) {
                    monthlyMax = double(m_finalValue[j]) / double(resultInteger) - 1;
                    monthlyMaxStock = j;
                }
            }
        }
        if (monthlyMax > globalMax) {
            globalMax = monthlyMax;
            m_investSelect[i][monthlyMaxStock] = globalMax;
        }
    }
    for (int i = 0 ; i < stockPrices.size() ; i++) {
        for (int j = 0 ; j < 999 ; j++) {
            if (m_investSelect[i][j] > 0) {
                totalGain += investCost * m_investSelect[i][j];
                investCost = 0;
            }
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

