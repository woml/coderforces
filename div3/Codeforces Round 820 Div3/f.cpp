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
const int INF = 0x3f3f3f3f;
vector<vector<int>> idx(10);

PII minv(PII a, PII b) {
    if (a < b) return a;
    return b;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, len, m, l, r, k;
        string s;
        cin >> s >> len >> m;
        n = s.size();
        vector<int> preSum(n + 1);
        for (int i = 0; i < 9; i++) idx[i].clear();

        s = "-" + s;
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + s[i] - '0';
        }

        for (int i = 1; i + len - 1 <= n; i++) {
            idx[(preSum[i + len - 1] - preSum[i - 1]) % 9].push_back(i);
        }
        while (m -- ) {
            cin >> l >> r >> k;
            PII ans = {INF, INF};
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (idx[i].size() == 0 || idx[j].size() == 0) continue;
                    if (((i * (preSum[r] - preSum[l - 1]) + j) % 9) != k) continue;
                    if (i == j) {
                        if (idx[i].size() >= 2)
                            ans = minv(ans, {idx[i][0], idx[i][1]});
                    } else {
                        ans = minv(ans, {idx[i][0], idx[j][0]});
                    }
                }
            }
            PII t = {INF, INF};
            if (ans == t) cout << "-1 -1" << endl;
            else cout << ans.first << " " << ans.second << endl;
        }
    }

    return 0;
}
