#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n, p, m;

void solve() {
    string s[2];
    cin >> s[0] >> s[1];
    n = s[0].size();
    s[0] = " " + s[0];
    s[1] = " " + s[1];
    int diff = 0;
    for (int i = 1; i <= n; i++) 
        if (s[0][i] != s[1][i]) diff++;
    cin >> p >> m;
    queue<pii> q;
    for (int i = 1; i <= m; i++) {
        int ty;
        cin >> ty;
        if (!q.empty() && q.front().first == i) {
            int x = q.front().second;
            if (s[0][x] != s[1][x]) diff++;
            q.pop();
        }
        if (ty == 3) {
            if (diff == 0) cout << "Yes\n";
            else cout << "No\n";
        } else if (ty == 1) {
            int x;
            cin >> x;
            if (s[0][x] != s[1][x]) diff--;
            q.push({i + p, x});
        } else {
            int s1, s2, x, y;
            cin >> s1 >> x >> s2 >> y;
            if (s[0][x] != s[1][x]) diff--;
            if (s[0][y] != s[1][y]) diff--;
            swap(s[s1 - 1][x], s[s2 - 1][y]);
            if (s[0][x] != s[1][x]) diff++;
            if (s[0][y] != s[1][y]) diff++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
