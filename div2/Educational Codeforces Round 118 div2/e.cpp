#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
string s[N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

void bfs(int sx, int sy) {
    queue<PII> mq;
    mq.push({sx, sy});
    while (mq.size()) {
        auto t = mq.front(); mq.pop();
        int tx = t.x, ty = t.y;
        for (int i = 0; i < 4; i++) {
            int nowx = tx + dx[i], nowy = ty + dy[i];
            if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= m || s[nowx][nowy] == '#') continue;
            int can = 0, arrive = 0;
            for (int j = 0; j < 4; j++) {
                int afterx = nowx + dx[j], aftery = nowy + dy[j];
                if (afterx < 0 || afterx >= n || aftery < 0 || aftery >= m || s[afterx][aftery] == '#') continue;
                can++;
                if (s[afterx][aftery] != '.') arrive++;
            }
            if (arrive && can - arrive <= 1 && s[nowx][nowy] == '.') {
                s[nowx][nowy] = '+';
                mq.push({nowx, nowy});
            }
        }
    }
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 'L') {
                    bfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%c", s[i][j]);
            printf("\n");
        }
    }
    return 0;
}
