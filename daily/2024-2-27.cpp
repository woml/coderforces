#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> idx(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int t = a[i];
        for (int j = 1; j * t <= 2 * n; j++) {
            if (t * j == i + idx[j] && i < idx[j]) ans++;
        }
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