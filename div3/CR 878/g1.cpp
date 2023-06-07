#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    map<int, int> cnt;
    int x, now = 1;
    ll step = 0;
    for (int i = 0; ; i++) {
        cin >> x;
        if (!cnt.count(x)) {
            cnt.insert({x, i});
        } else {
            int t = cnt[x];
            step = (ll)(t + 1 + i) * (i - t) / 2;
            break;
        }
        cout << "+ " << now++ << endl;
        cout.flush();
    }
    cout << "! " << step << endl;
    cout.flush();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
