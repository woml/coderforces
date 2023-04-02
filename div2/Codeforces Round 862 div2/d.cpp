#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int depth[N], h[N], e[N], ne[N], idx;
int sz[N];

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void bfs(int u) {
    memset(depth, 0x3f, sizeof depth);
    queue<int> q;
    depth[u] = 0;
    q.push(u);
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (depth[j] > depth[t] + 1) {
                depth[j] = depth[t] + 1;
                q.push(j);
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b); add(b, a);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {

    }
    std::cout << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
