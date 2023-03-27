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

LL a[N], b[N];

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        LL ans = 1, pre_gcd = b[1] * a[1], pre_lcm = b[1];
        for (int i = 2; i <= n; i++) {
            pre_gcd = gcd(pre_gcd, b[i] * a[i]);
            pre_lcm = pre_lcm * b[i] / gcd(pre_lcm, b[i]);
            if (pre_gcd % pre_lcm == 0) continue;
            pre_gcd = b[i] * a[i];
            pre_lcm = b[i];
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
