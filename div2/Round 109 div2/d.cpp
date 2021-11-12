#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5050, INF = 0x3f3f3f3f;
int f[N][N], pos[N], q[N];
int n, cnt;

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        if (q[i] == 1) pos[++ cnt] = i;
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[0][i] = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i][j], f[i][j - 1]);
            if (q[j] == 0) 
                f[i][j] = min(f[i - 1][j - 1] + abs(j - pos[i]), f[i][j]);
        }
    }
    cout << f[cnt][n] << endl;
    return 0;
}