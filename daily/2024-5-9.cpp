#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<ll, 2> l2;

const ll inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<l2>> e(n + 1);

    // build graph
    for (ll i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, 2 * w});
        e[v].push_back({u, 2 * w});
    }
    for (ll i = 1, a; i <= n; i++) {
        cin >> a;
        e[0].push_back({i, a});
    }

    // dijkstra
    priority_queue<l2, vector<l2>, greater<l2>> q;
    vector<bool> vis(n + 1);
    vector<ll> dist(n + 1, inf);
    dist[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        ll d = t[0], rank = t[1];
        if (vis[rank]) continue;
        vis[rank] = true;
        for (auto [v, w] : e[rank]) {
            if (dist[v] > dist[rank] + w) {
                dist[v] = dist[rank] + w;
                q.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}