#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool solve() {
    int a, b, cnt0 = 0;
    ll C;
    cin >> a >> b >> C;
    ll x = 0, y = 0;
    for (int i = 59; i >= 0; i--) {
        if (C >> i & 1) {
            if (a >= b && a > 0) {
                x += 1ll << i;
                a--;
            } else if (b > a && b > 0) {
                y += 1ll << i;
                b--;
            } else {
                return false;
            }
        } else cnt0++;
    }
    if (a != b || a > cnt0) return false;
    for (int i = 59; i >= 0; i--) {
        if (!(C >> i & 1) && a > 0) {
            x += 1ll << i;
            y += 1ll << i;
            a--;
        }
    }
    cout << x << " " << y << "\n";
    // cout << bitset<sizeof(x)*8>(x) << "\n";
    // cout << bitset<sizeof(y)*8>(y) << "\n";
    // cout << __builtin_popcount(x) << " " << __builtin_popcount(y) << "\n";
    // cout << (x ^ y) << "\n";
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!solve()) {
        cout << "-1\n";
    }
    return 0;
}