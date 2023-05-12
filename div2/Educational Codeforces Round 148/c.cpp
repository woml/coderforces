#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int a[N];

void solve() {
    int n, ans = 0, d = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {
            if (d == -1) ans++;
            d = 1;
        } else if (a[i] < a[i + 1]) {
            if (d == 1) ans++;
            d = -1;
        }
    }
    if (d != 0) ans++;
    cout << ans + 1 << "\n";
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
