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

const int M = 5e6, N = M + 10;

int cnt[N];
LL dp[N];
int n, x;

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%d", &x);
        cnt[x]++;
    }
    // cnt[i] represent for the total sum j that take i as factor
    for (int i = 1; i <= M; i++) {
        for (int j = i + i; j <= M; j += i) {
            cnt[i] += cnt[j];
        }
    }
    // If the array is a1, a2, ..., ak. gcd result is d1, d2, d3, ...., dk.
    // The maximum permutation of array a, must have this premise: d1 > d2 > d3 .... > dk
    // Because the maximun result is k*d1 + (k - 1)*d2 + ... + dk, if i > j & di < dj, we can swap di dj to get larger result.
    // which means (k - i + 1)*di + (k - j + 1)*dj < (k - i + 1)*dj + (k - j + 1)*di  ==> (k - i + 1)(di - dj) < (k - j + 1)(di - dj) 
    // ==> k - i + 1 > k - j + 1 ==> j < i
    // dp[i] stands for the set that all arrays the last element is i. The value of dp[i] is the max of the set.
    // As i is the last element of array, so it guarantee that if j in front of i, j must be divisible by i (j = ki; k = 2,...,)
    // so the state transition is from i to j i which is dp[i] to dp[j]
    // On the assumption that i only one number, so dp[i] is cnt[i] * i
    // then as j can be divisible by i, so cnt[i] = cnt[j] + ? (? is the total number can be divide by i but cannot by j)
    // dp[j] is j i, so dp[j] = cnt[j] * j + (cnt[i] - cnt[j]) * i  ==> cnt[j]*(j - i) + cnt[i]*i
    // Because cnt[i]*i is dp[i], so the state transition is: dp[j] = max(dp[j], cnt[j](j - i) + dp[i])
    // Finally traversal all dp[i] to find out the maximum
    dp[1] = cnt[1] * 1;
    LL ans = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = i + i; j <= M; j += i) {
            dp[j] = max(dp[j], (LL)cnt[j] * (j - i) + dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
