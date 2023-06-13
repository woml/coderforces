#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int q;
    cin >> q;
    int minv = -1, maxv = -1, minv2 = -1;
    for (int i = 0, x; i < q; i++) {
        cin >> x;
        if (!i) {
            minv = maxv = x;
            cout << "1";
        }
        else {
            if (x >= maxv && minv2 == -1) {
                maxv = x;
                cout << "1";
            } else if (x <= minv && minv2 == -1) {
                    minv2 = x;
                    cout << "1";
            } else if (minv2 == -1) cout << "0";
            else if (x >= minv2 && x <= minv) {
                minv2 = x;
                cout << "1";
            } else cout << "0";
        }
    }
    cout << "\n";
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
