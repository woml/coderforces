#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int a[N], b[N];

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt_a, cnt_b, cnt;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]] = 1;
    for (int i = 0; i < n; i++) cin >> b[i], cnt[b[i]] = 1;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[j]) j++;
        if (!cnt_a.count(a[i])) cnt_a.insert({a[i], j - i + 1});
        else cnt_a[a[i]] = max(cnt_a[a[i]], j - i + 1);
        i = j;
    }
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && b[j + 1] == b[j]) j++;
        if (!cnt_b.count(b[i])) cnt_b.insert({b[i], j - i + 1});
        else cnt_b[b[i]] = max(cnt_b[b[i]], j - i + 1);
        i = j;
    }
    int ans = 0;
    for (auto [k, v] : cnt) {
        ans = max(ans, cnt_a[k] + cnt_b[k]);
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
