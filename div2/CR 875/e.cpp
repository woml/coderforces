#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 3e5 + 10, mod = 998244353;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int n, k;
int fac[N], inv[N];

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
    cin >> n >> k;
    vector<ll> d(n + 2);
    fac[0] = 1, inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (ll)fac[i - 1] * i % mod;
        inv[i] = quick_mod(fac[i], mod - 2);
    }
    for (int i = 0, l, r; i < k; i++) {
        cin >> l >> r;
        ll x = rng();
        d[l] ^= x; d[r + 1] ^= x;
    }
    map<ll, int> cnt;
    for (int i = 1; i <= n; i++) {
        d[i] ^= d[i - 1];
        cnt[d[i]]++;
    }
    ll ans = 1;
    for (auto [_, v] : cnt) {
        if (v & 1) ans = 0;
        else ans = (ll)fac[v] * inv[v / 2] % mod * inv[v / 2] % mod * quick_mod(v / 2 + 1, mod - 2) % mod * ans % mod;
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
