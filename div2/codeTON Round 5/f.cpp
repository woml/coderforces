#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5050;

vector<int> e[N];
int n, m;


void dfs(int u, int fa, vector<int> &dep, vector<int> &cnt) {
    cnt[dep[u]]++;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u, dep, cnt);
    }
}

void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> ans(n + 1);
    for (int root = 1; root <= n; root++) {
        vector<int> dep(n + 1), cnt(n);
        dfs(root, -1, dep, cnt);
        int del = 0, k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                k++;
                del += i;
                ans[k] = max(ans[k], (n - 1) * k - 2 * del);
            }   
        }
    }
    for (int i = 0; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
