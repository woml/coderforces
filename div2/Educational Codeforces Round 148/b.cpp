#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int a[N];
ll sum[N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    ll ans = 0;
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        ans = max(ans, sum[n - r] - sum[l * 2]);
    }
    cout << ans << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
