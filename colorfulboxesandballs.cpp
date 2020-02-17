#include <iostream>
using namespace std;

class ColorfulBoxesAndBalls {
public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors);
};

int ColorfulBoxesAndBalls::getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
    return max((numRed * onlyRed + numBlue * onlyBlue), numRed > numBlue ? (2 * numBlue * bothColors + (numRed - numBlue) * onlyRed) : (2 * numRed * bothColors + (numBlue - numRed) * onlyBlue));
}
