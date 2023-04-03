#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int depth[N], h[N], e[N], ne[N], idx;
int sz[N];

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u, int father, int depth, std::vector<int> &d) {
    d[u] = depth;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != father) dfs(j, u, depth + 1, d);
    }
}

void solve() {
    int n;
    std::cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a - 1, b - 1); add(b - 1, a - 1);
    }
    std:vector<int> d1(n), d2(n);
    dfs(0, -1, 0, d1);
    int a = std::max_element(d1.begin(), d1.end()) - d1.begin();
    dfs(a, -1, 0, d1);
    int b = std::max_element(d1.begin(), d1.end()) - d1.begin();
    dfs(b, -1, 0, d2);
    for (int i = 0; i < n; i++) {
        d1[i] = std::max(d1[i], d2[i]);
    }
    std::sort(d1.begin(), d1.end());
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (ans < n && d1[ans] < i) ans++;
        std::cout << std::min(n, ans + 1) << " ";
    }
    std::cout << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
