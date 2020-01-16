#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FriendScore{
public:
    int highestScore(vector<string> friends);
};

int FriendScore::highestScore(vector<string> friends) {
    vector<int> friendNumber;
    int maxFriendNumber = 0;
    for (int i = 0 ; i < int(friends.size()) ; i++) {
        friendNumber.clear();
        friendNumber.push_back(i);
        for (int j = 0 ; j < int(friends[i].length()) ; j++) {
            if (friends[i][j] == 'Y') {
                friendNumber.push_back(j);
                for (int k = 0 ; k < int(friends[j].length()) ; k++) {
                    if (friends[j][k] == 'Y') friendNumber.push_back(k);
                }
            }
        }
        sort(friendNumber.begin(), friendNumber.end());
        friendNumber.erase(unique(friendNumber.begin(),friendNumber.end()),friendNumber.end());
        maxFriendNumber = max(maxFriendNumber, int(friendNumber.size()));
    }    
    return maxFriendNumber - 1;    
}