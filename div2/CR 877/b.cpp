#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] == 1) {
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == n) idx = i;
        }
        cout << idx << " " << 2 << "\n";
    } else if (a[n] == 1) {
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == n) idx = i;
        }
        cout << idx << " " << n - 1 << "\n";
    } else {
        int idx1 = -1, idx2 = -1, idx = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) idx1 = i;
            if (a[i] == 2) idx2 = i;
            if (a[i] == n) idx = i;
        }
        if (idx1 > idx2) {
            if (idx > idx1) cout << idx1 << " " << idx << "\n";
            else if (idx < idx2) cout << idx2 << " " << idx << "\n";
            else cout << idx << " " << idx << "\n";
        } else if (idx1 < idx2) {
            if (idx < idx1) cout << idx1 << " " << idx << "\n";
            else if (idx > idx2) cout << idx2 << " " << idx << "\n";
            else cout << idx << " " << idx << "\n";
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