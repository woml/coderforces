#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> odd;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) {
            if (!odd.count(a[i])) odd.insert(a[i]);
        }
    }
    bool can = true;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) continue;
        if (odd.lower_bound(a[i]) == odd.begin()) {
            can = false;
            break;
        }
    }
    if (can) {
        cout << "Yes\n";
        return;
    }
    can = true;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) continue;
        if (odd.lower_bound(a[i]) == odd.begin()) {
            can = false;
            break;
        }
    }
    if (can) cout << "Yes\n";
    else cout << "No\n";
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
