#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n, l, r;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == n) idx = i;
    }
    if (idx == 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == n - 1) idx = i;
        }
        if (idx == n) {
            l = r = idx;
            while (l - 1 > 0 && a[l - 1] > a[1]) l--;
        } else {
            r = l = idx - 1;
            while (l - 1 > 0 && a[l - 1] > a[1]) l--;
        }
    } else if (idx == n) {
        l = r = idx;
        while (l - 1 > 0 && a[l - 1] > a[1]) l--;
    } else {
        r = l = idx - 1;
        while (l - 1 > 0 && a[l - 1] > a[1]) l--;
    }
    for (int i = r + 1; i <= n; i++) cout << a[i] << " ";
    for (int i = r; i >= l; i--) cout << a[i] << " ";
    for (int i = 1; i < l; i++) cout << a[i] << " ";
    cout << "\n";
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
