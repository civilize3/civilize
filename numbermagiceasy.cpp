#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy {
public:
    int theNumber(string answer);
};

int NumberMagicEasy::theNumber(string answer) {
    int result = 0;
    for (int i = 0 ; i < answer.size() ; i++) {
        result = result << 1;
        if (answer.at(i) == 'N') result++;
    }
    return result + 1;
}

