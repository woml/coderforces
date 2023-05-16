#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    ll ans = 1;
    for (int i = n - 1, r = n, t = 0; ~i; i--, t++) {
        while (r >= 1 && a[r - 1] > b[i]) r--;
        if (n - r - t <= 0) {
            ans = 0;
            break;
        } 
        ans = (ans * (n - r - t)) % mod;
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
