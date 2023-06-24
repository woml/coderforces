#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
int a[N], last[N], n;
int f[N][2];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0, sizeof f);
    memset(last, 0, sizeof last);
    map<int, int> l;
    for (int i = 1; i <= n; i++) {
        if (l.count(a[i])) {
            last[i] = l[a[i]];
        }
        l[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        if (last[i]) {
            f[i][1] = max(f[last[i]][0] + i - last[i] + 1, f[last[i]][1] + i - last[i]);
        }
        // cout << "i = " << i << " " << f[i][0] << " " << f[i][1] << "\n";
    }
    cout << max(f[n][0], f[n][1]) << "\n";
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
