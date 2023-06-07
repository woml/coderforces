#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
int a[N];
int n, k, q;

void solve() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = q + 1;
    ll ans = 0;
    int p = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] <= q) p++;
        else {
            if (p >= k) {
                ans += (ll)(p - k + 2) * (p - k + 1) / 2;
            }
            p = 0;
        }
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
