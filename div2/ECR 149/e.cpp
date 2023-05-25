#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 6e5, mod = 998244353;

int s[N], k, n, win[N];

void solve() {
    cin >> k;
    n = 1 << k;
    s[1] = 1;
    for (int i = 2; i <= n; i++) s[i] = (ll)s[i] * i % mod;
    
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
