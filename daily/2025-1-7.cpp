#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> sum(m+1), arr(n+1);
    map<int, int> cnt, last, len;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
        last[arr[i]] = 0;
    }
    int t = cnt.size();
    sum[0] = t;
    for (int i = 0, p, v; i < m; i++) {
        cin >> p >> v;
        cnt[arr[p]]--;
        if (cnt[arr[p]] == 0) {
            t--;
            len[arr[p]] += i+1-last[arr[p]];
        }
        arr[p] = v;
        cnt[v]++;
        if (cnt[v] == 1) {
            t++;
            last[v] = i+1;
        }
        sum[i+1] = t;
    }
    for (auto [k, v] : cnt) {
        if (v != 0) {
            len[k] += m+1-last[k];
        }
    }
    ll ans = 0;
    for (auto [k, v] : len) {
        // cout << k << " " << v << "\n";
        int t = m+1-v;
        ans += (ll)(m+1)*m/2 - (ll)t*(t-1)/2;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) solve();
    return 0;
}