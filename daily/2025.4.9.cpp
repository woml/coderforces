#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int q[100005];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> f(n+1, vector<ll>(2));
    vector<ll> sum(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    int hh = 0, bb = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        if (i - q[hh] > k) hh++;
        f[i][1] = sum[i] + f[q[hh]][0] - sum[q[hh]];
        ll t = f[i][0] - sum[i];
        while (hh <= bb && f[q[bb]][0] - sum[q[bb]] <= t) bb--;
        q[++bb] = i;
    }

    ll ans = max(f[n][0], f[n][1]);
    cout <<ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}