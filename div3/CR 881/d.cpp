#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

vector<int> e[N];
int son[N];

void dfs(int u, int fa) {
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        son[u] += son[v];
        // cout << "u = " << u << " son[u] = " << son[u] << "\n";
    }
}

void solve() {
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) e[i].clear(), son[i] = 0;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 1 && i != 1) son[i] = 1;
    }
    dfs(1, -1);
    cin >> q;
    while (q -- ) {
        int u, v;
        cin >> u >> v;
        // cout << "u = " << u << " v = " << v << "\n";
        // cout << "son[u] = " << son[u] << " son[v] = " << son[v] << "\n";
        cout << (ll)son[u] * son[v] << "\n";
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
