#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

int a[N];

void solve() {
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += abs(a[i]);
    }
    int l = 1, r = n, times = 0;
    while (l <= r) {
        if (times % 2 == 0) {
            while (a[l] >= 0 && l <= r) l++;
            while (a[r] >= 0 && l <= r) r--;
            if (l > r) break;
            while (a[l] <= 0 && l <= r) l++;
            while (a[r] <= 0 && l <= r) r--;
            times++;
            if (l > r) break;
        } else {
            while (a[l] <= 0 && l <= r) l++;
            while (a[r] <= 0 && l <= r) r--;
            if (l > r) break;
            while (a[l] >= 0 && l <= r) l++;
            while (a[r] >= 0 && l <= r) r--;
            times++;
            if (l > r) break;
        }
    }
    cout << ans << " " << times << "\n";
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
