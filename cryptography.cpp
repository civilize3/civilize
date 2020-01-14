#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cryptography
{
public:
    long long encrypt(vector<int> numbers);
};

long long Cryptography::encrypt(vector<int> numbers) {
    vector<int>::iterator it = min_element(numbers.begin(), numbers.end());
    numbers[distance(numbers.begin(), it)]++;
    long long result = 1;
    for (it = numbers.begin() ; it != numbers.end() ; ++it)
        result *= *it;
    return result;
}

