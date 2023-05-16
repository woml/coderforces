#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 5e3 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<pair<int, int>> stk;
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        int t = 0;
        while (!stk.empty()) stk.pop();
        for (int r = l; r <= n; r++) {
            if (stk.empty()) {
                stk.push({a[r], a[r]});
            } else {
                int mv = a[r];
                while (!stk.empty()) {
                    auto minv = stk.top().first, maxv = stk.top().second;
                    if (a[r] > maxv) {
                        stk.push({a[r], mv});
                        break;
                    } else if (a[r] < minv) {
                        t++;
                        mv = max(mv, maxv);
                        stk.pop();
                    } else {
                        t++;
                        stk.pop();
                        stk.push({minv, max(maxv, mv)});
                        break;
                    }
                }
                if (stk.empty()) {
                    stk.push({a[r], mv});
                }
            }
            ans += t;
        }
    }
    cout << ans << "\n";
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
