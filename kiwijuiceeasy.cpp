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

int main() {
    int cc[] = {700000,800000,900000,1000000};
    int bot[] = {478478,478478,478478,478478};
    int f[] = {2,3,2,0,1};
    int t[] = {0,1,1,3,2};
    vector<int> cap(cc, cc + sizeof(cc) / sizeof(int));
    vector<int> bottles(bot, bot + sizeof(bot) / sizeof(int));
    vector<int> from(f, f + sizeof(f) / sizeof(int));
    vector<int> to(t, t + sizeof(t) / sizeof(int));
    vector<int> result;

    //cap.push_back(20);

    KiwiJuiceEasy kje;
    result = kje.thePouring(cap,bottles,from,to);

    for (vector<int>::iterator i = result.begin() ; i != result.end() ; ++i)
        cout << *i << endl;

    return 0;
}
