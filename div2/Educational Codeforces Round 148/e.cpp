#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10, mod = 998244353;

void solve() {
    int n, a1, x, y, k, m;
    cin >> n >> a1 >> x >> y >> m >> k;
    vector<int> a(n + 1);
    a[1] = a1;
    for (int i = 2; i <= n; i++) {
        a[i] = ((ll)a[i - 1] * x + y) % m;
    }
    for (int i = 0; i <= k; i++) {
        vector<int> b(n + 1);
        b[1] = a[1];
        for (int j = 2; j <= n; j++) b[j] = (b[j - 1] + a[j]) % mod;
        swap(a, b);
    }
    ll ans = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        ans ^= (ll)(i + k - 1) * a[i];
    }
    cout << ans << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
