#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 100;

int a[N], b[N], c[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d %d", &a[i], &b[i]);
        int ans = 1;
        c[1] = 0;
        for (int i = 2; i <= n; i++) {
            int t = gcd(b[i], b[i - 1]);
            int d1 = b[i] / t, d2 = b[i - 1] / t;
            if (c[i - 1]) {
                int k = c[i - 1] / d1;
                d2 *= k;
            }
            // cout << "i = " << i << " " << d1 << " " << d2 << endl;
            c[i] = 0;
            if (a[i - 1] % d1 == 0 && a[i] % d2 == 0) {
                c[i] = d2;
                continue;
            }
            ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}
