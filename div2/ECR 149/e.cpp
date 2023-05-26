#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 6e5, mod = 998244353;

int s[N], k, n, win[N], comb[N];
ll ans;

int quick_mod(int a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return (int)res;
}

bool solve() {
    cin >> k;
    n = 1 << k;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s[i] = --x;
    }
    int now = k;
    comb[0] = 1;
    ans = 1;
    for (int i = 1; i <= n; i++) comb[i] = (ll)comb[i - 1] * i % mod;
    while (n > 1) {
        int l_1 = 0, r_1 = (1 << (now - 1)) - 1;
        int l_2 = r_1 + 1, r_2 = (1 << now) - 1;
        now--;
        int cnt_win = 0, cnt_lose = 0;
        for (int i = 0; i < n / 2; i++) win[i] = -2;
        for (int i = 0; i < n; i++) {
            if (s[i] >= l_1 && s[i] <= r_1) win[i / 2] = s[i], cnt_win++;
            else if (s[i] >= l_2 && s[i] <= r_2) cnt_lose++, win[i / 2] = s[i ^ 1];
            if (i > 1) {
                if (s[i] >= l_1 && s[i] <= r_1 && s[i ^ 1] >= l_1 && s[i ^ 1] <= r_1) return false;
                if (s[i] >= l_2 && s[i] <= r_2 && s[i ^ 1] >= l_2 && s[i ^ 1] <= r_2) return false;
            }
        }
        int lose_un = n / 2 - cnt_lose, win_un = n / 2 - cnt_win;
        ans = ans * comb[lose_un] % mod * quick_mod(2, min(win_un, lose_un)) % mod;
        n /= 2;
        swap(s, win);
    }
    return true;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    if(!solve()) ans = 0;
    cout << ans << "\n";
    return 0;
}
