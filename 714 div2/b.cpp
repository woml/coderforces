#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10, MOD = 1e9 + 7;

int a[N], mi[N];

int main(void) {
    int T;
    cin >> T;
    mi[0] = 1;
    for (int i = 1; i <= 200001; i++) {
        mi[i] = (LL)mi[i - 1] * i % MOD;
    }
    while (T --) {
        int n;
        cin >> n;
        unordered_map<int, int> cnt;
        int ee = (1 << 30) - 1;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            ee = ee & x;
            cnt[x]++;
        }
        int ans = 0;
        if (cnt[ee] > 1) {
            int k = cnt[ee];
            int t = (LL)k * (k - 1) % MOD;
            ans = (LL)t * mi[n - 2] % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}