#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    ll ans = 0;
    if (k == 1) {
        cout << (ll)a * (n - 1) << "\n";
        return;
    }
    
    while (n != 0) {
        if (n % k != 0) {
            ans += (ll)(n % k) * a;
            n -= n % k;
        } else {
            int t = n / k;
            ll add1 = (ll)(n - t) * a;
            if (add1 < b) ans += add1;
            else ans += b;
            n = t;
        }
    }
    cout << ans - a << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    
    return 0;
}