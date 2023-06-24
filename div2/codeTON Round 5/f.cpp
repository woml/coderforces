#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5050;

vector<int> e[N];
vector<int> dep;
int sz[N], f[N], c[N];
int n, m;

void dfs_1(int u, int fa) {
    sz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs_1(v, u);
        sz[u] += sz[v];
        f[u] += f[v];
    }
    f[u] += sz[u] - 1;
}

void dfs_2(int u, int fa) {
    for (auto v : e[u]) {
        if (v == fa) continue;
        c[v] = c[u] + f[u] - f[v] - sz[v] + n - sz[v];
        dfs_2(v, u);
    }
}

void dfs_3(int u, int fa, int t) {
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs_3(v, u, t + 1);
    }
    if (e[u].size() == 1) {
        dep.push_back(t);
    }
}

void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs_1(1, -1);
    dfs_2(1, -1);
    int root = 1;
    for (int i = 1; i <= n; i++) {
        // cout << f[i] << " " << c[i] << "\n";
        if (f[i] + c[i] < f[root] + c[root]) root = i;
    }
    dfs_3(root, -1, 0);
    sort(dep.begin(), dep.end());
    m = dep.size();
    // cout << "m = " << m << "\n";
    // for (int i = 0; i < m; i++) cout << dep[i] << " ";
    for (int k = 0; k <= n; k++) {
        int del = 0, now = 0, depth = 1;
        for (int i = 1, j = now; i < k; i++) {
            del += depth;
            if (dep[j] == depth) now++;
            j++;
            if (j == m) {
                j = now;
                depth++;
            }
        }
        cout << k * (n - 1) - del * 2 << " ";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
