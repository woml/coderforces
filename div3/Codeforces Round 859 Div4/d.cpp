#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL sum[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }
        while (q -- ) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            LL t = sum[n] - sum[r] + sum[l - 1] + k * (r - l + 1); 
            // cout << t << endl;
            if (t & 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
