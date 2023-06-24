#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n, m;

void solve() {
    cin >> n >> m;
    ll a = 0, b = 0;
    for (int i = 0, x; i < n; i++) cin >> x, a += x;
    for (int i = 0, x; i < m; i++) cin >> x, b += x;
    if (a > b) cout << "Tsondu\n";
    else if (a < b) cout << "Tenzing\n";
    else cout << "Draw\n";
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
