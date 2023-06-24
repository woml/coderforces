#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int a[N], b[N], c[N];

bool check(int t, int x) {
    for (int i = 30; ~i; i--) {
        int l = t >> i & 1, r = x >> i & 1;
        if (l == 1 && r == 0) return false;
    }
    return true;
}

void solve() {
    int n, x, t = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        if (check(t | a[i], x)) {
            t |= a[i];
        } else break;
    }
    for (int i = 0; i < n; i++) {
        if (check(t | b[i], x)) {
            t |= b[i];
        } else break;
    }
    for (int i = 0; i < n; i++) {
        if (check(t | c[i], x)) {
            t |= c[i];
        } else break;
    }
    if (t == x) cout << "Yes\n";
    else cout << "No\n";
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
