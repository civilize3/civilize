#include <iostream>
using namespace std;

class NotTwo{
public:
    int maxStones(int width, int height);
};

int NotTwo::maxStones(int width, int height) {    
    if (width <=2 && height <= 2) return width * height;
    int maxStones = 0;
    
    for (int i = 1 ; i <= height ; i++) {
        int rest = 0;
        if (i % 4 == 1) {
            if (width % 4 == 1) rest = 1;
            else if (width % 4 == 2 || width % 4 == 3) rest = 2;
        }
        else if (i % 4 == 2) {
            if (width % 4 == 2) rest = 1;
            else if (width % 4 == 3) rest = 2;
            else if (width % 4 == 1) rest = 0;
        }
        else if (i % 4 == 3) {
            if (width % 4 == 1 || width % 4 == 2) rest = 0;
            else if (width % 4 == 3) rest = 1;
        }
        else 
            if (width % 4 == 1 || width % 4 == 2 || width % 4 == 3) rest = 1;
        maxStones += int(width / 4) * 2 + rest;
    }
    return maxStones;
}