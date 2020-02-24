#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class HiddenNumbers{
public:
    vector<string> findAll(vector<string> text);
};

vector<string> HiddenNumbers::findAll(vector<string> text) {
    vector<string> parsedNumber;
    vector<string> result;
    vector<bool> done(text.size());
    int numOfNumbers;
    int resultSize;
    for (int i = 0 ; i < text.size() ; i++) {
        numOfNumbers = 0;
        for (int j = 0 ; j < text[i].size() ; j++) {
            if (isdigit(text[i].at(j))) {
                numOfNumbers++;
                if (j == text[i].size() - 1) parsedNumber.push_back(text[i].substr(j + 1 - numOfNumbers, numOfNumbers));
            }
            else if (numOfNumbers != 0 || j == text[i].size() - 1) {
                parsedNumber.push_back(text[i].substr(j - numOfNumbers, numOfNumbers));
                numOfNumbers = 0;
            }
        }
    }
    resultSize = parsedNumber.size() % 2 == 1 ? (parsedNumber.size() + 1) / 2 : parsedNumber.size() / 2;
    
    while (result.size() < resultSize) {
        string next;
        for (int i = 0 ; i < parsedNumber.size() ; i++) {
            if (!done[i] && (next.empty() || stoll(parsedNumber[i]) > stoll(next))) {
                next = parsedNumber[i];
            }
            else if (!done[i] && (next.empty() || stoll(parsedNumber[i]) == stoll(next))) {
                if (parsedNumber[i].length() > next.length()){
                    next = parsedNumber[i];
                }
            }
        }
        
        for (int i = 0 ; i < parsedNumber.size() ; i++) {
            if (parsedNumber[i] == next) {
                result.push_back(parsedNumber[i]);
                done[i] = true;
            }
            if (result.size() >= resultSize) break;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

