#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int a[N], b[N], n;

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int j = 1; j <= q; j++) {
        int k;
        cin >> k;
        for (int i = 1; i <= n; i++) b[i] = a[i];
        if (abs(n - k) % 2 == 0) {
            for (int i = 1; i <= n; i++) b[i] = a[i] + max(k - i + 1, 0);
            k -= n;
        }
        else {
            for (int i = 1; i < n; i++) b[i] = a[i] + max(k - i + 1, 0);
            k -= n - 1;
        }
        sort(b + 1, b + 1 + n);
        k = (max(k, 0) + 1) / 2;
        ll diff = 0;
        for (int i = 1; i <= n; i++) diff += b[i] - b[1];
        int ans = b[1];
        if (diff < k) {
            ans -= (k - diff + n - 1) / n;
        } 
        cout << ans << " ";
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
