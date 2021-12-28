#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int a[N];
LL sum[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        LL k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
        int ans = 2e9;
        if (sum[n] <= k) printf("0\n");
        else {
            for (int len = 0; len < n; len++) {
                LL temp = k - sum[n - len] + sum[1], t;
                if (temp > 0) t = temp / (len + 1);
                else t = (temp - len) / (len + 1);
                //cout << "len = " << len << " " <<  t << endl;
                ans = min((LL)ans, max(a[1] - t, (LL)0) + len);
                //cout << "len = " << len << " " <<  t << " ans = " << ans << endl;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
/*
while (l < r) {
                    LL mid = l + r + 1 >> 1;
                    // cout << "mid = " << mid << endl;
                    if (sum[n - len] - sum[1] + (len + 1) * mid > k) r = mid - 1;
                    else l = mid;
                }
                // cout << "l = " << l << endl;
                
                */
