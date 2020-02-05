#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CorporationSalary {
public:
    long long totalSalary(vector<string> relations);
};

long long CorporationSalary::totalSalary(vector<string> relations) {
    long long employee[relations.size()] = { 0 };
    long long sum = 0;
    bool isFull = false;
    bool isManager;

    int j = 0;
    while(!isFull) {
        if (employee[j] == 0) {
            isManager = false;
            for (int i = 0 ; i < relations[j].length(); i++) {
                if (relations[j].at(i) == 'Y') {
                    isManager = true;
                    if(employee[i] > 0) sum += employee[i];
                    else {
                        sum = 0;
                        break;
                    }
                }
            }
            if(!isManager) employee[j] = 1;
            else {
                employee[j] = sum;
                sum = 0;
            }
        }
        j++;
        if (j == relations.size()) {
            isFull = true;
            for (int i = 0 ; i < relations.size() ; i++)
                if (employee[i] == 0) isFull = false;
            j = 0;
        }
    }
    sum = 0;
    for (int i = 0 ; i < relations.size() ; i++)
        sum += employee[i];
    return sum;
}

