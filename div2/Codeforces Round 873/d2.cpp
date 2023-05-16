#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int a[N], n, b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = i;
    sort(b + 1, b + 1 + n, [&](int x, int y) {
        return a[x] < a[y];
    });
    set<int> in, out;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (ll)i * (n - i);
    }
    for (int i = 1; i <= n; i++) in.insert(i);
    in.insert(0); in.insert(n + 1);
    out.insert(0); out.insert(n + 1);
    for (int i = 1; i <= n; i++) {
        in.erase(b[i]); out.insert(b[i]);
        auto r_u_it = in.lower_bound(b[i]);
        int r_upper = *r_u_it;
        int c_l = b[i] - *prev(r_u_it), c_r = 0;
        if (r_upper != n + 1) {
            c_r = *out.lower_bound(r_upper) - r_upper;
        }
        ans -= (ll)c_l * c_r;
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
