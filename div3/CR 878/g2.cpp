#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 1;
map<int, int> cnt;
int k = 300, d = 350;

void solve() {
    int x, mx;
    cin >> x;
    mx = x;
    for (int i = 0; i < k; i++) {
        auto t = rng() % N;
        cout << "+ " << t << endl;
        cout.flush();
        cin >> x;
        mx = max(mx, x);
    }
    cnt.insert({x, 0});
    for (int i = 1; i < d; i++) {
        cout << "+ " << 1 << endl;
        cout.flush();
        cin >> x;
        if (cnt.count(x)) {
            cout << "! " << i << endl;
            cout.flush();
            return ;
        } else {
            cnt.insert({x, i});
        }
    }
    cout << "+ " << mx << endl;
    cout.flush();
    for (int i = 0; i <= d; i++) {
        cin >> x;
        if (cnt.count(x)) {
            cout << "! " << i * d + d - 1 - cnt[x] + mx << endl;
            cout.flush();
            return ;
        }
        cout << "+ " << d << endl;
        cout.flush();
    }
}   

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
