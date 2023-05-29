#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int,3> i3;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
vector<pii> e[N];
int n, d[N], ans;

void solve() {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) d[i] = 0, e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    d[1] = 1;
    queue<i3> q;
    q.push({1, -1, -1});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int u = t[0], fa = t[1], c = t[2];
        ans = max(ans, d[u]);
        for (auto [v, w] : e[u]) {
            if (v == fa) continue;
            if (w < c) d[v] = d[u] + 1;
            else d[v] = d[u];
            q.push({v, u, w});
        }
    }

    cout << ans << "\n";
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
