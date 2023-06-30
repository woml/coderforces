#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

int dmax[N], dmin[N];

vector<pair<int,int>> e[N];
array<int, 3> query[N];

void dfs(int u, int mx, int mn) {
    for (auto [v, w] : e[u]) {
        int t1 = max(mx + w, 0);
        int t2 = min(mn + w, 0);
        dmax[v] = t1, dmin[v] = t2;
        dmax[v] = max(dmax[v], dmax[u]);
        dmin[v] = min(dmin[v], dmin[u]);
        dfs(v, t1, t2);
    }
}

void solve() {
    int m, n = 1, t = 0;
    cin >> m;
    e[1].clear();
    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        if (op[0] == '+') {
            int v, w;
            cin >> v >> w;
            e[v].push_back({++n, w});
            e[n].clear();
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            query[t++] = {u, v, k};
        }
    }
    dmax[1] = 1;
    dfs(1, 1, 0);
    for (int i = 0; i < t; i++) {
        auto v = query[i][1], k = query[i][2];
        if (dmin[v] <= k && dmax[v] >= k) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
