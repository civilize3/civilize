#include <cstdio>
#include <string>
using namespace std;

string rev(string str) {
    string output = "";
    for (int i = str.length() - 1 ; i >= 0 ; i--)
        output += str[i];
    return output;
}

int main() {
    char N[1000];
    scanf("%s", N);
    string n(N);
    string n16 = n + "0000";
    string n_rev = rev(n);
    string n16_rev = rev(n16);
    int carry = 0;
    string result = "";
    for (int i = 0 ; i < n.length() ; i++) {
        if (n_rev[i] - '0' + n16_rev[i] - '0' + carry == 3) { carry = 1; result += "1"; }
        else if (n_rev[i] - '0' + n16_rev[i] - '0' + carry == 2) { carry = 1; result += "0"; }
        else if (n_rev[i] - '0' + n16_rev[i] - '0' + carry == 1) { carry = 0; result += "1"; }
        else { carry = 0; result += "0"; }
    }
    for (int i = n.length() ; i < n16.length() ; i++) {
        if (n16_rev[i] - '0' + carry == 2) { carry = 1; result += "0"; }
        else if (n16_rev[i] - '0' + carry == 1) { carry = 0; result += "1"; }
        else { carry = 0; result += "0"; }
    }
    if (carry == 1) result += "1";
    printf("%s\n", rev(result).c_str());

    return 0;
}
