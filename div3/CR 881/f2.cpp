#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, K = 19;

struct info {
    ll sum, minpre, minsuf, minv, maxpre, maxsuf, maxv;
};

info operator + (const info &a, const info &b) {
    return info{
        a.sum + b.sum,
        min(a.minpre, a.sum + b.minpre),
        min(b.minsuf, b.sum + a.minsuf),
        min(min(a.minv, b.minv), a.minsuf + b.minpre),
        max(a.maxpre, a.sum + b.maxpre),
        max(b.maxsuf, b.sum + a.maxsuf),
        max(max(a.maxv, b.maxv), a.maxsuf + b.maxpre)
    };
}

info make(int x) {
    return info{x, min(x, 0), min(x, 0), min(x, 0), max(x, 0), max(x, 0), max(x, 0)};
}

info rev(const info &a) {
    return info{a.sum, a.minsuf, a.minpre, a.minv, a.maxsuf, a.maxpre, a.maxv};
}

vector<pii> e[N];
int fa[N][K], dep[N], a[N];
info s[N][K]; 

void solve() {
    int m, n = 1, q = 0;
    cin >> m;
    e[1].clear();
    dep[1] = a[1] = 1;
    while (m -- ) {
        string op;
        int u, v, k;
        cin >> op;
        if (op[0] == '+') {
            cin >> u >> k;
            e[u].push_back({++n, k});
            e[n].clear();
            dep[n] = dep[u] + 1;
            a[n] = k;
            fa[n][0] = u, s[n][0] = make(k);
            for (int i = 1; i < K; i++) {
                fa[n][i] = 0, s[n][i] = make(0);
                fa[n][i] = fa[fa[n][i - 1]][i - 1];
                s[n][i] = s[n][i - 1] + s[fa[n][i - 1]][i - 1];
            }
        } else {
            cin >> u >> v >> k;
            info pl = make(0), pr = make(0);
            if (dep[u] < dep[v]) swap(u, v);
            for (int i = K - 1; i >= 0; i--) {
                if (dep[fa[u][i]] >= dep[v]) {
                    pl = pl + s[u][i];
                    u = fa[u][i];
                }
            }
            for (int i = K - 1; i >= 0; i--) {
                if (fa[u][i] != fa[v][i]) {
                    pl = pl + s[u][i];  u = fa[u][i];
                    pr = pr + s[v][i];  v = fa[v][i];
                }
            }
            if (u != v) {
                pl = pl + s[u][0];
                pr = pr + s[v][0];
                u = fa[u][0];
            }
            info ans = pl + make(a[u]) + rev(pr);
            if (ans.minv <= k && ans.maxv >= k) cout << "YES\n";
            else cout << "NO\n";
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
