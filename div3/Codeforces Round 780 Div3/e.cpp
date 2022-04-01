#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2020;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        char g[N][N];
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <=n; j++)
                if (g[i][j] == '1') cnt1++;

        int cnt_dia = 0;
        for (int i = 0; i < n; i++) {
            int x = i - 1, y = -1;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                x = (x + 1) % n;
                y = (y + 1) % n;
                if (g[x][y] == '1') cnt++;
            }
            cnt_dia = max(cnt_dia, cnt);
        }
        int ans = cnt1 - cnt_dia + n - cnt_dia;
        cout << ans << endl;
    }

    return 0;
}
