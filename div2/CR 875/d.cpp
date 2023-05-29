#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n;

void solve() {
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first;
    for (int i = 0; i < n; i++) cin >> a[i].second;
    ll ans = 0;
    sort(a.begin(), a.end());
    vector<int> cnt(n + 1);
    for (int a1 = 1; a1 * a1 <= 2 * n; a1++) {
        cnt.assign(n + 1, 0);
        for (auto [a2, b2] : a) {
            int b1 = a2 * a1 - b2;
            if (1 <= b1 && b1 <= n) ans += cnt[b1];
            if (a2 == a1) cnt[b2]++;
        }
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
