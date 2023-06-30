#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int ans = 0, t = 0;
    if (yb >= ya && yc >= ya) {
        ans += min(yb, yc) - ya + 1;
        t++;
    } else if (yb <= ya && yc <= ya) {
        ans += ya - max(yb, yc) + 1;
        t++;
    }
    if (xb >= xa && xc >= xa) {
        ans += min(xb, xc) - xa + 1;
        t++;
    } else if (xb <= xa && xc <= xa) {
        ans += xa - max(xb, xc) + 1;
        t++;
    }
    if (t == 2) ans--;
    if (ans == 0) ans = 1;
    cout << ans << "\n";
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
