#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (s[i] == '?') {
                s[i] = '0';
            }
        } else {
            if (s[i] == '?') {
                if (s[i - 1] == '1') s[i] = '1';
                else s[i] = '0';
            }
        }
    }
    cout << s << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
