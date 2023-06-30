#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 3e5 + 10;

int pre[N][10];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 10; j++) pre[i][j] = 0;
    vector<int> last(10);
    for (int i = 1; i <= n; i++) {
        int t = s[i - 1] - '0';
        for (int j = 0; j < 10; j++) pre[i][j] = last[j];
        last[t] = i;
    }
    for (int j = 0; j < 10; j++) pre[n + 1][j] = last[j];
    int m;
    string sl, sr;
    cin >> m >> sl >> sr;
    int p = n + 1;
    for (int i = m - 1; ~i; i--) {
        int mx = N;
        int l = sl[i] - '0', r = sr[i] - '0';
        for (int j = l; j <= r; j++) {
            mx = min(mx, pre[p][j]);
        }
        if (mx == 0) {
            cout << "YES\n";
            return;
        }
        p = mx;
        // cout << "i = " << i << " mx = " << mx << "\n";
    }
    cout << "NO\n";
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
