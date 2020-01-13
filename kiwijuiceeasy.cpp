#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KiwiJuiceEasy
{
public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId);
};

vector<int> KiwiJuiceEasy::thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
    int to = 0;
    int moves = 0;
    for (vector<int>::iterator i = fromId.begin() ; i != fromId.end() ; ++i) {
        moves = min(bottles[*i], capacities[toId[to]] - bottles[toId[to]]);
        bottles[*i] -= moves;
        bottles[toId[to]] += moves;
        to++;
    }
    return bottles;
}
