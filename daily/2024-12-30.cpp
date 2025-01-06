#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n ;
    map<long long, int> cnt;
    long long sum = 0;
    cin >> n;
    vector<int> f(n+1);
    cnt[0] = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        sum += x;
        if (cnt.count(sum) == 1) {
            f[i] = f[cnt[sum]] + 1;
        }
        cnt[sum] = i;
        f[i] = max(f[i], f[i-1]);
    }
    cout << f[n] << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T --) solve();
    return 0;
}