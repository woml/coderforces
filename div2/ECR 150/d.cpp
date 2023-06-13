#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        a[i] = {l, r};
    }
    sort(a.begin(), a.end());
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        if (i) f[i] = max(f[i - 1], f[i]);
        for (int j = i + 1; j < n; j++) {
            if (a[j].first > a[i].second) break;
            int r = max(a[i].second, a[j].second);
            int k = lower_bound(a.begin(), a.end(), make_pair(r + 1, 0)) - a.begin();
            f[k] = max(f[k], f[i] + 2);
            // cout << "i = " << i << " j = " << j << "\n";
        }
    }
    cout << n - max(f[n], f[n - 1]) << "\n";
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
