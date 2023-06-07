#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    map<int, int> cnt;
    int x, now = 1;
    cin >> x;
    cnt.insert({x, 0});
    for (int i = 1; i <= 1000; i++) {
        cout << "+ " << 1 << endl;
        cout.flush();
        cin >> x;
        if (!cnt.count(x)) cnt.insert({x, i});
        else {
            cout << "! " << i << endl;
            cout.flush();
            return;
        }
    }
    for (int i = 1; ; i++) {
        cout << "+ " << 1000 << endl;
        cout.flush();
        cin >> x;
        if (cnt.count(x)) {
            cout << "! " << i * 1000 + 1000 - cnt[x] << endl;
            cout.flush();
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
