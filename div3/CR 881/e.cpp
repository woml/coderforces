#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

pii a[N];
int b[N], s[N];
int n, m, q;

bool check(int mid) {
    for (int i = 1; i <= n; i++) s[i] = 0;
    for (int i = 1; i <= mid; i++) s[b[i]] = 1;
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];
    for (int i = 0; i < m; i++) {
        int l = a[i].first, r = a[i].second;
        int ones = s[r] - s[l - 1];
        if (ones > r - l + 1 - ones) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> b[i];
    int l = 1, r = q;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l == q && !check(q)) cout << "-1\n";
    else cout << l << "\n";
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
