#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
const ll inf = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    n++;
    vector<int> a(n + 1);
    vector<ll> s(n + 1);
    vector<int> r(n + 1);
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] += s[i - 1] + a[i];
    stack<pair<ll, int>> upper;
    for (int i = 1; i <= n; i++) {
        while (!upper.empty() && upper.top().first > s[i]) {
            r[upper.top().second] = i;
            upper.pop();
        }
        upper.push({s[i], i});
    }

    ll sum = s[n], ans = 0;
    for (int i = 1; i <= n; i++) {
        ll tmp = s[n], k = s[i], p = i;
        if (s[i] < ans) continue;
        while (r[p] != 0) {
            tmp += k - s[r[p]];
            k = s[r[p]];
            p = r[p];
        }
        if (tmp > sum) {
            sum = tmp;
            ans = s[i];
        }
    }
    
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
