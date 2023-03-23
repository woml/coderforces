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
        cin >> s;
        vector<int> cnt(11);
        for (int i = 0; i < 4; i++) cnt[s[i] - '0']++;
        int c = 0;
        for (int i = 0; i < 10; i++) {
            c = max(c, cnt[i]);
        }
        if (c == 4) cout << -1 << endl;
        else if (c == 3) cout << 6 << endl;
        else cout << 4 << endl;
    }

    return 0;
}
