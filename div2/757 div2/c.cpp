#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
const LL MOD = 1e9 + 7;

LL quick_pow(LL a, LL b, LL mod) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = (a * res) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, m;
        scanf("%d %d", &n, &m);
        LL ans = 0, total = 0;
        for (int i = 0; i < m; i++) {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            total |= x;
        }
        cout << total * quick_pow(2, n - 1, MOD) % MOD << endl;
    }

    return 0;
}
