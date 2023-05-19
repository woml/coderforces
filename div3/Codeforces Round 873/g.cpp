#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

vector<int> e[N];
map<pair<int,int>, int> idx;
vector<int> ans;
bool f;

int dfs(int u, int fa) {
    int res = 1, cnt = 0, used = 0;
    cout << "u = " << u << " fa = " << fa << "\n";
    for (auto v : e[u]) {
        if (v == fa) continue;
        int t = dfs(v, u);
        if (t == -2) ans.push_back(idx[{u, v}]);
        else if (t == -1) {
            if (used == 1) f = false;
            used = 1;
            cnt++;
        } else {
            cnt += t;
        }
    }
    if (cnt > 2) {
        f = false;
    } else if (cnt == 2) {
        if (used == 1) f = false;
        res = -2; // cut
    } else if (cnt == 1) {
        res = -1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    f = true;
    for (int i = 1; i <= n; i++) e[i].clear();
    idx.clear();
    ans.clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        idx[{u, v}] = i;
        idx[{v, u}] = i;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1);
    if (!f) cout << "-1\n";
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