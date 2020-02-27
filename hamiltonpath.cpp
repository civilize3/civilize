#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class HamiltonPath {
public:
    int countPaths(vector<string> roads);
private:
    int connectedCity(string road);
    long long factorial(int n);
};

int HamiltonPath::countPaths(vector<string> roads) {
    int twoCityConnected = 0;
    int threeCityConnected = 0;

    for (int i = 0 ; i < roads.size() ; i++) {
        if (connectedCity(roads[i]) > 2) return 0;
        else if (connectedCity(roads[i]) == 2) {
            for (int j = 0 ; j < roads.size() ; j++) {
                if (roads[i].at(j) == 'Y' && connectedCity(roads[j]) >= 2) return 0;
            }
            threeCityConnected++;
        }
        if (connectedCity(roads[i]) == 1) {
            for (int j = 0 ; j < roads.size() ; j++) {
                if (roads[i].at(j) == 'Y' && connectedCity(roads[j]) == 1) twoCityConnected++;
            }
        }
    }

    return (int(pow(2, twoCityConnected / 2)) * int(pow(2, threeCityConnected)) * factorial(roads.size() - twoCityConnected / 2 - threeCityConnected * 2)) % 1000000007;
}

int HamiltonPath::connectedCity(string road) {
    int result = 0;
    for (int j = 0 ; j < road.length() ; j++) {
        if (road[j] == 'Y') result++;
    }
    return result;
}

long long HamiltonPath::factorial(int n) {
    if (n == 1) return 1;
    else return n*factorial(n - 1);
}
