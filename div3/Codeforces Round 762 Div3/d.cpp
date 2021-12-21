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

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, m;
        cin >> m >> n;
        vector<vector<int>> g(m, vector<int>(n));
        vector<vector<PII>> q(n, vector<PII>(m));
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cin >> g[j][i];
            }
        }
        int tt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                q[i][j] = {g[j][i], j};
            }
        }
        for (int i = 0; i < n; i++) {
            sort(q[i].begin(), q[i].end(), [](PII a, PII b){
                return a.first > b.first;
            });
        }
        unordered_map<int, int> st;
        int cnt = 0, minv = 1e9, second_max = -1;
        for (int i = 0; i < n; i++) {
            if (st[q[i][0].second] == 0) {
                st[q[i][0].second] = 1;
                cnt++;
            }
            if (minv > q[i][0].first) minv = q[i][0].first;
        }
        for (int j = 0; j < m; j++) {
            sort(g[j].begin(), g[j].end());
            second_max = max(second_max, g[j][n - 2]);
        }
        if (cnt != n) {
            cout << minv << endl;
        } else {
            int c = -1;
            cout << min(second_max, minv) << endl;
        }
    }

    return 0;
}
