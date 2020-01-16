#include <iostream>
#include <string>
using namespace std;

class ThePalindrome{
public: 
    int find(string s);
};

int ThePalindrome::find(string s) {
    int subtractLength = 0;
    for (int i = 0; i < s.length() - 1 ; i++) {
        if (s[i] == s[s.length() - 1]) {
            for (int j = i; j < s.length() - 1; j++) {
                if (s[j] == s[s.length() - 1 - subtractLength]) subtractLength++;
                else {
                     subtractLength = 0;
                     break;
                }
            }
        }
        if (subtractLength > 0) break;
    }
    subtractLength++;
    return 2 * s.length() - subtractLength;
}
