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

LL f[50], x, y;

bool dfs(LL w, LL h) {
    // std::cout << << "" w << " "
    if (w == 2 && h == 1) return true;
    if (y > h) {
        LL new_x = w - y + 1, new_y = x;
        x = new_x, y = new_y;
        return dfs(h, w - h);
    }
    else if (y <= w - h) {
        LL new_x = w - h - y + 1, new_y = x;
        x = new_x, y = new_y;
        return dfs(h, w - h);
    }
    return false;
}

void solve() {
    int n;
    std::cin >> n >> x >> y;
    LL w = f[n + 1], h = f[n];
    if (dfs(w, h)) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    f[0] = f[1] = 1;
    for (int i = 2; i <= 46; i++) f[i] = f[i - 2] + f[i - 1];
    while (cases -- ) {
        solve();
    }

    return 0;
}
