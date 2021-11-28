// Dp problem

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int M = 2e7, N = M + 10;

bool st[N];
int cnt[N];
LL dp[N];
int n, x;

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &x);
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                cnt[j]++;
                if (j * j != x) cnt[x / j]++;
                st[j] = st[x / j] = true;
            }
        }
    }
    // cnt[i] represent for the total sum j that take i as factor
    LL ans = 0;
    dp[1] = cnt[1] * 1;
    for (int i = 1; i <= M; i++) {
        if (st[i]) {
            for (int j = i + i; j <= M; j += i) {
                if (st[j]) {
                    dp[j] = max(dp[j], (LL)cnt[j] * (j - i) + dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
