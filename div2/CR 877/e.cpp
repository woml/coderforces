#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10, mod = 1e9 + 7;

int quick_mod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0, x; i < n; i++) cin >> x;
    // k^m - ...
    int ans = quick_mod(k, m), t;
    for (int i = 0; i < n; i++) {
        if (i == 0) t = 1;
        else t = (ll)t * (m - i + 1) % mod * quick_mod(i, mod - 2) % mod;
        int p = (ll)t * quick_mod(k - 1, m - i) % mod;
        ans = ((ll)ans + mod - p) % mod;
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
