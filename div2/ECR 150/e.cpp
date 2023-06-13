#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    ll m;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    cin >> m;
    sort(a.begin(), a.end());
    map<int, int> cnt;
    cnt.insert({0, n}); cnt.insert({n + 1, n});
    vector<ll> sz(n + 1);
    sz[n] = n;
    for (int i = n - 1; ~i; i--) {
        int h = a[i].first, loc = a[i].second;
        auto r = cnt.upper_bound(loc), l = prev(r);
        sz[r->first - l->first - 1] -= h;
        sz[r->first - loc - 1] += h;
        sz[loc - l->first - 1] += h;
        cnt.insert({loc, h});
    }

    ll ans = 0;
    for (int i = n; i > 1; i--) {
        if (sz[i] == 0) continue;
        ll k = min(m / i, sz[i]);
        ans += (i - 1) * k;
        sz[i] -= k;
        m -= i * k;
        if (m > 0 && m < i) {
            if (sz[i] > 0) {
                ans += m - 1;
                m = 0;
            }
        }
        if (m == 0) break;
    }
    cout << ans << "\n";

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }

    return 0;
}
