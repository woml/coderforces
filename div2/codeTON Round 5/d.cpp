#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 110;
const ll inf = 1e18;

int n, m;
vector<array<int, 2>> e[N];
ll a[N];
bool st[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) e[i].clear(), a[i] = inf;
    memset(st, 0, sizeof st);
    
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    a[n] = 0;
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || a[j] < a[t])) t = j;
        }
        if (t == -1) break;
        st[t] = true;
        for (auto [v, w] : e[t]) {
            a[v] = min(a[v], a[t] + w);
        }
    }
    // for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    vector<string> ans;
    if (a[1] == inf) cout << "inf\n";
    else {
        int cnt = 0;
        cout << a[1];
        while (a[1] != 0) {
            ll t = inf;
            string s;
            cnt++;
            for (int i = 1; i <= n; i++) {
                if (a[i] != 0) t = min(t, a[i]);
            }
            for (int i = 1; i <= n; i++) {
                if (a[i]) {
                    s.push_back('1');
                    a[i] -= t;
                } else s.push_back('0');
            }
            s.push_back(' ');
            s += to_string(t);
            ans.push_back(s);
        }
        cout << " " << cnt << "\n";
        for (int i = 0; i < cnt; i++) cout << ans[i] << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();

    return 0;
}
