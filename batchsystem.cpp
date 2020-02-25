#include <iostream>
#include <vector>
#include <map>
using namespace std;

class BatchSystem {
public:
    vector<int> schedule(vector<int> duration, vector<string> user);
};

vector<int> BatchSystem::schedule(vector<int> duration, vector<string> user) {
    vector<int> result;
    vector<bool> isAssigned(duration.size());
    map<string, int> jobAssign;
    for (int i = 0 ; i < duration.size() ; i++) jobAssign[user[i]] += duration[i];

    while(duration.size() != result.size()) {
        string next;
        for (int i = 0 ; i < duration.size() ; i++) {
            if (!isAssigned[i] && (next.empty() || jobAssign[user[i]] < jobAssign[next])) next = user[i];
        }
        for (int i = 0 ; i < duration.size() ; i++) {
            if (jobAssign[next] == jobAssign[user[i]]) {
                result.push_back(i);
                isAssigned[i] = true;
            }
        }
    }
    return result;
}
