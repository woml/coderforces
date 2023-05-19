#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int sz[N];
vector<pair<int,int>> e[N];
vector<int> ans;
bool f;

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto [v, idx] : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (sz[v] == 3) {
            ans.push_back(idx);
            sz[v] = 0;
        }
        sz[u] += sz[v];
    }
    if (sz[u] > 3) f = false;
}

void solve() {
    int n;
    cin >> n;
    f = true;
    for (int i = 1; i <= n; i++) e[i].clear();
    ans.clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    dfs(1, -1);
    if (!f || sz[1] != 3) cout << "-1\n";
    else {
        int n = ans.size();
        cout << n << "\n";
        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
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