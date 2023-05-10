#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 10, mod = 1e9 + 7;

int n, k, ans, sz[N], inv;
int fact[N], infact[N];
vector<int> e[N];

ll qmi(int a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = (ll)a * a % mod;
    }
    return res;
}

void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (ll)fact[i - 1] * i % mod;;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}

int c(int b, int a) {
    if (a < b) return 0;
    return (ll)fact[a] * infact[a - b] % mod * infact[b] % mod;
}

void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        ans = (ans + (ll)c(k / 2, sz[v]) * c(k / 2, n - sz[v]) % mod * inv) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    ans = 1;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (k % 2 == 0) {
        init();
        inv = qmi(c(k, n), mod - 2);
        dfs(1, 0);
    }
    cout << ans << "\n";

    return 0;
}