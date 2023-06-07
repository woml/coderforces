#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

int n, a[N];

bool check(int mid) {
    int cnt = -1, l = -2e9, r = -2e9;
    for (int i = 1; i <= n; i++) {
        if (a[i] - mid > r || a[i] + mid < l) {
            cnt++;
            l = a[i] - mid, r = a[i] + mid;
        } else {
            l = max(l, a[i] - mid);
            r = min(r, a[i] + mid);
        }
        // cout << a[i] << "\n";
        // cout << "l = " << l << " r = " << r << " cnt = " << cnt << "\n";
        if (cnt >= 3) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    // check(9);
    cout << l << "\n";
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
