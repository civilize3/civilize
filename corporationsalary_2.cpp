#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CorporationSalary {
private:
    long long m_employee[50];
    
public:
    long long totalSalary(vector<string> relations);
    long long salary(int index, vector<string> relations);
};

long long CorporationSalary::totalSalary(vector<string> relations) {
    long long sum = 0;
    for (int i = 0 ; i < 50 ; i++)
        m_employee[i] = 0;
    for (int i = 0 ; i < relations.size() ; i++)
        sum += salary(i, relations);
    return sum;
}

long long CorporationSalary::salary(int index, vector<string> relations) {
    if(m_employee[index] != 0) return m_employee[index];
    long long sum = 0;
    for (int i = 0 ; i < relations[index].length() ; i++) {
        if (relations[index].at(i) == 'Y')
            sum += salary(i, relations);       
    }       
    if (sum == 0)
        sum++;

    m_employee[index] = sum;
    return sum;
}