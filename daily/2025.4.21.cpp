#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;

int count(int x) {
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0;
    vector<int> sumD(11);
    for (int i = 0; i < n; i++) sumD[count(arr[i])]++;
    for (int i = 0; i < n; i++) {
        sumD[count(arr[i])]--;
        for (ll j = 1, base = 10; j < 11; j++, base *= 10) {
            ans = (ans + sumD[j] * base % mod * arr[i] % mod) % mod;
        }
        ans = (ans + 1ll * i * arr[i]) % mod;
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}