#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class InterestingParty{
public:
    int bestInvitation(vector<string> first, vector<string> second);

};

int InterestingParty::bestInvitation(vector<string> first, vector<string> second) {
    map<string,int> gatherInteresting;
    vector<string>::iterator iter;
    map<string,int>::iterator iterMap;
    int numCount = 0;
    for(iter = first.begin() ; iter != first.end() ; ++iter) {
        gatherInteresting[first[numCount]] = 0;
        gatherInteresting[second[numCount]] = 0;
        numCount++;
    }
    numCount = 0;
    for(iter = first.begin() ; iter != first.end() ; ++iter) {
        gatherInteresting[first[numCount]]++;
        gatherInteresting[second[numCount]]++;
        numCount++;
    }
    numCount = 0;
    for(iterMap = gatherInteresting.begin() ; iterMap != gatherInteresting.end() ; ++iterMap) {
        numCount = max(numCount,iterMap->second);
    }
    
    return numCount;
}

