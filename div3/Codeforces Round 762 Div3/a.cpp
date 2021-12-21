#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        string s;
        unordered_map<char, int >h;
        cin >> s;
        int n = s.size();
        bool f = true;
        if (s.size() % 2) f= false;
        for (int i = 0, j = n / 2; j < n;i ++, j++) {
            if (s[i] != s[j]) f = false;
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
