#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n, k;


void solve() {
    cin >> n >> k;
    int ans = 0;
    vector<int> s;
    for (int i = 30; ~i; i--) {
        if (n >> i & 1) s.push_back(i);
    }
    if (s[0] >= k) {
        ans = pow(2, k);
    } else {
        for (int i = 0; i < s.size(); i++) {
            ans += pow(2, s[i]);
        }
        ans++;
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
