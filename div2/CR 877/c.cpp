#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

bool check(int p) {
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m));
    if (check(n)) {
        int now = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i][j] = ++now;
            }
        }
    } else if (check(m)) {
        int now = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = ++now;
            }
        }
    } else {
        int now = 0;
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = ++now;
            }
        }
        for (int i = 1; i < n; i += 2) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = ++now;
            }
        }
    }
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cout << ans[i][j] << " \n"[j == m - 1];
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
