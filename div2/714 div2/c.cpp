#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;

int cnt[20], f[200010][10];

int dp(int k, int p) {
    if (k == 0) return 1;
    if (f[k][p] != -1) return f[k][p];
    int res = 0;
    if (p == 9) res = dp(k - 1, 0) + dp(k - 1, 1);
    else res = dp(k - 1, p + 1);
    return f[k][p] = res % MOD;
}

int main(void) {
    int T;
    cin >> T;
    memset(f, -1, sizeof f);
    while (T--) {
        int n, m;
        scanf("%d %d",&n ,&m);
        int ans = 0;
        while (n) {
            ans = (ans + dp(m, n % 10)) % MOD;
            n /= 10;
        }
        printf("%d\n", ans);
    }
    return 0;
}