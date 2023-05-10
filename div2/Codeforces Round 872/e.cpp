#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
const int N = 1e5 + 10;

map<int, int> cnt[N];
int arr[N], ans, n;
vector<int> e[N];

void dfs(int u, int fa) {
    int mx = 1, son = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        arr[v] ^= arr[u];
        dfs(v, u);
        son++;
        if (cnt[u].size() < cnt[v].size()) swap(cnt[u], cnt[v]);
        for (auto [k, v] : cnt[v]) {
            cnt[u][k] += v;
            mx = max(mx, cnt[u][k]);
        }
    }
    if (!son) cnt[u][arr[u]] = 1;
    else ans += son - mx;

    if (mx != 1) {
        for (auto it = cnt[u].begin(); it != cnt[u].end(); ) {
            if (it->second == mx) {
                it->second = 1;
                it = next(it);
            } else it = cnt[u].erase(it);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans + !cnt[1].count(0) << "\n";
    return 0;
}