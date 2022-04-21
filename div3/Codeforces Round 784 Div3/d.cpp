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
        int n;
        string s;
        cin >> n >> s;
        s = 'W' + s + 'W';
        n += 2;
        bool ans = true;
        // check wbw or wrw
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (s[i] == 'W') continue;
            if (s[i - 1] == 'W') cnt++;
            if (s[i + 1] == 'W') cnt++;
            if (cnt == 2) ans = false;
        }
        // cout << ans << endl;
        // cout << n << " " << s << endl;
        // check rrrrr or bbbbb
        int st = 0, has_else = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'W') {
                if (st == 0) {
                    if (s[i] == 'B') st = 1;
                    else st = 2;
                } else if (st == 1) {
                    if (s[i] == 'R') has_else = 1;
                } else {
                    if (s[i] == 'B') has_else = 1;
                }
            } else {
                if (has_else == 0 && st != 0) ans = false;
                st = 0, has_else = 0;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
