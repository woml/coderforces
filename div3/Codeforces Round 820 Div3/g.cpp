#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7, INF = 0x3f3f3f3f;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size(), last = -1;
        vector<int> flag(n, 0);
        for (int i = 0; i + m - 1 < n; i++) 
            if (s.substr(i, m) == t) flag[i] = 1, last = i;
        
        // First is the operation num to make s without t, second is how many num operation.
        // dp(i) = {x, y} means use x operation to make 0~i-1 index in s without t.
        vector<PII> dp(n + 1, {n + 1, 0});

        dp[0] = {0, 1};
        for (int i = 0; i <= n; i++) {
            for (int j = i; j + m <= n; j++) {
                if (j - i >= m && flag[j - m]) break;
                if (flag[j]) {
                    if (dp[i].first + 1 < dp[j + m].first) dp[j + m] = {dp[i].first + 1, dp[i].second};
                    else if (dp[i].first + 1 == dp[j + m].first) dp[j + m].second = (dp[i].second + dp[j + m].second) % MOD;
                }
            }
        }

        PII ans = {INF, INF};
        for (int i = last + 1; i <= n; i++) {
            // cout << dp[i].first << " " << dp[i].second << "--" << endl;
            if (ans.first > dp[i].first) {
                ans = {dp[i].first, dp[i].second};
            } else if (ans.first == dp[i].first) {
                ans = {dp[i].first, (ans.second + dp[i].second) % MOD};
            }
        }
        if (ans == PII{INF, INF}) cout << "-1 -1" << endl;
        else cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
