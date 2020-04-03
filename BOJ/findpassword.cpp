#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N,M;
    scanf ("%d %d", &N, &M);
    char url[21];
    char password[21];
    map<string,string> m;
    vector<string> urlList;

    for (int i = 0 ; i < N ; i++) {
        scanf("%s %s", url, password);
        m[url] = password;
    }

    for (int i = 0 ; i < M ; i++) {
        scanf("%s", url);
        urlList.push_back(url);
    }
    for (int i = 0 ; i < M ; i++)
        printf("%s\n", m[urlList[i]].c_str());

    return 0;
}
