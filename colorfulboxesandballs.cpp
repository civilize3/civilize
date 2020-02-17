#include <iostream>
using namespace std;

class ColorfulBoxesAndBalls {
public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors);
};

int ColorfulBoxesAndBalls::getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) {
    return max((numRed * onlyRed + numBlue * onlyBlue), numRed > numBlue ? (2 * numBlue * bothColors + (numRed - numBlue) * onlyRed) : (2 * numRed * bothColors + (numBlue - numRed) * onlyBlue));
}

int main()
{
    ColorfulBoxesAndBalls cbab;
    cout << cbab.getMaximum(2,3,100,400,200) << endl;
    cout << cbab.getMaximum(2,3,100,400,300) << endl;
    cout << cbab.getMaximum(5,5,464,464,464) << endl;
    cout << cbab.getMaximum(1,4,20,-30,-10) << endl;
    cout << cbab.getMaximum(9,1,-1,-10,4) << endl;

    return 0;
}

