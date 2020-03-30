#include <cstdio>
#include <string>
#include <iostream>

int main () {
    std::string str;
    std::cin >> str;
    
    int result = 0;
    char prev = 'A';
    for (unsigned int i = 0 ; i < str.length() ; i++) {
        int move = str.at(i) - prev > 0 ? str.at(i) - prev : prev - str.at(i);
        result += move <= 13 ? move : 26 - move;
        prev = str.at(i);
    }
    printf("%d\n", result);
    return 0;
}
