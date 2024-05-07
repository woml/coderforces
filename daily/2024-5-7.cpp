#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(ll mid, ll n) {
    ll t1 = 0, t2 = 0;
    while (n) {
        if (n <= mid) {
            t1 += n;
            break;
        }
        n -= mid;
        t1 += mid;
        ll add = n / 10;
        t2 += add;
        n -= add;
    }
    // cout << t1 << " " << t2 << "\n";
    return t1 >= t2;
}

void solve() {
    ll n;
    cin >> n;
    ll l = 1, r = n;
    check(4, n);
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid, n)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}