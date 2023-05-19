#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n), b(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[i] = {x, i};
    }
    for (int i = 0, x; i < n; i++) cin >> b[i].first;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        b[i].second = a[i].second;
    }
    sort(b.begin(), b.end(), [&](PII &x, PII &y) {
        return x.second < y.second;
    });
    for (int i = 0; i < n; i++) cout << b[i].first << " \n"[i == n - 1];
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
