#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e4 + 10, M = 110, mx = N + M;

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<bitset<mx>>> st(n + 1, vector<bitset<mx>>(m + 1));
    int r, idx = 0;
    cin >> r;
    for (int i = 0; i < r; i++) {
        int t, d, x;
        cin >> t >> d >> x;
        if (t >= mx) continue;
        if (d == 1) 
            for (int j = 0; j <= m; j++) st[x][j][t] = 1;
        else 
            for (int j = 0; j <= n; j++) st[j][x][t] = 1;
    }
    queue<array<int,3>> q;
    // [x, y, t]
    q.push({0, 0, 0});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p[0], y = p[1], t = p[2];
        if (x == n && y == m) {
            cout << t << "\n";
            return;
        }
        if (x + 1 <= n && t + 1 < mx && !st[x + 1][y][t + 1]) q.push({x + 1, y, t + 1}), st[x + 1][y][t + 1] = 1;
        if (y + 1 <= m && t + 1 < mx && !st[x][y + 1][t + 1]) q.push({x, y + 1, t + 1}), st[x][y + 1][t + 1] = 1;
        if (t + 1 < mx && !st[x][y][t + 1]) q.push({x, y, t + 1}), st[x][y][t + 1] = 1;
    }
    cout << "-1\n";
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