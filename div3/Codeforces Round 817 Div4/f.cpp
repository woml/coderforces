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
char s[55][55], st[55][55];
bool ans;
int dx[] = {0, 1, 0, -1, -1, -1, 1, 1}, dy[] = {1, 0, -1, 0, -1, 1, -1, 1};
int w, h;

void bfs(int sx, int sy) {
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = 1;
    int cnt = 1;
    string towards;
    while (q.size()) {
        auto t = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < w && y >= 0 && y < h && !st[x][y] && s[x][y] == '*') {
                if (i < 4 || (i > 3 && s[t.first][y] != '*' && s[x][t.second] != '*')) {
                    q.push({x, y});
                    cnt++;
                    st[x][y] = 1;
                    towards.push_back(i + '0');
                }
            }
        }
    }

    if (cnt != 3 || towards[0] == towards[1] || towards[0] > '3' || towards[1] > '3') {
        ans = false;
    }
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        cin >> w >> h;
        memset(s, 0, sizeof s);
        memset(st, 0, sizeof st);
        ans = true;
        for (int i = 0; i < w; i++) cin >> s[i];

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (s[i][j] == '*' && !st[i][j]) bfs(i, j);
                if (!ans) break;
            }
            if (!ans) break;
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
