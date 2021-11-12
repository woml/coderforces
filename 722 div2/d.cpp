#include <iostream> 
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 1e6 + 10, MOD = 998244353;

LL s[N], p[N], ans[N];
int n;

void cnt(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = i + i; j <= x; j += i) {
            p[j]++;
        }
    }
}

int main(void) {
    s[0] = 1, s[1] = 1, ans[0] = 1, ans[1] = 1;
    cin >> n;
    cnt(n);
    for (int i = 1; i <= n; i++) {
        ans[i] = (s[i - 1] + p[i]) % MOD;
        s[i] = (s[i - 1] + ans[i]) % MOD;
    }
    cout << ans[n] << endl;
    return 0;
}