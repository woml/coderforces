#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

typedef std::pair<int, int> PII;
const int N = 55;
char g[N][N];
int st[N][N], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
PII q[N * N];

bool dfs(int sx, int sy, int gp) {
    memset(st, 0, sizeof st);
    int hh = 0, tt = -1, n = sx, m = sy, cnt = 0;
    q[++ tt] = {sx, sy};
    while (hh <= tt) {
        auto p = q[hh ++];
        for (int k = 0; k < 4; k++) {
            int x = dx[k] + p.first, y = dy[k] + p.second;
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (g[x][y] == '#' || st[x][y]) continue;
            st[x][y] = 1;
            if (g[x][y] == 'G') cnt++;
            q[++ tt] = {x, y};
        }
    }
    return cnt == gp;
}

bool solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> g[i] + 1;
    int gp = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'G') gp++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'B') {
                if (i == n && j == m) return false;
                if (((i == n - 1 && j == m) || (i == n && j == m - 1)) && gp) return false;
                for (int k = 0; k < 4; k++) {
                    int x = dx[k] + i, y = dy[k] + j;
                    if (x < 1 || x > n || y < 1 || y > m) continue;
                    if (g[x][y] == 'G') return false;
                    if (g[x][y] == '.') g[x][y] = '#';
                }
            }
        }
    }
    return dfs(n, m, gp);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T -- ) {
        if (solve()) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
}