#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
        cout << "YES\n";
        cout << n << "\n";
        for (int i = 1; i <= n; i++) cout << "1" << " \n"[i == n];
    } else {
        if (n % 2 == 0) {
            if (k == 1) cout << "NO\n";
            else {
                cout << "YES\n";
                cout << n / 2 << "\n";
                for (int i = 2; i <= n; i += 2) cout << "2" << " \n"[i == n];
            }
        } else {
            bool ans = false;
            for (int i = k; i > 1; i--) {
                int t = n, cnt = 0;
                while (t >= i) {
                    t -= i;
                    cnt++;
                    if (t != 1 && t <= k) {
                        ans = true;
                        cout << "YES\n";
                        if (t > 0) cout << cnt + 1 << "\n";
                        else cout << cnt << "\n";
                        for (int j = 1; j <= cnt; j++) cout << i << " ";
                        if (t > 0) cout << t;
                        cout << "\n";
                        return;
                    }
                }
            }
            cout << "NO\n";
        }
    }
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