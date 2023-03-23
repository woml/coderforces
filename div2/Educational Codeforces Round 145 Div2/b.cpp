#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

bool check(LL m, LL n) {
    m /= 2;
    LL sum = 1 + 4 * (1 + m) * m;
    return sum >= n;
}
bool check1(LL m, LL n) {
    LL sum = (1 + m) * (m + 1);
    return sum >= n;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        LL n;
        cin >> n;
        // From 0
        LL l = 0, r = 1e9;
        LL ans = 1e18;
        while (l < r) {
            LL mid = l + r >> 1;
            if (check(mid, n)) r = mid;
            else l = mid + 1;
        }
        ans = l;
        // cout << "l = " << l;
        l = 1, r = 1e9;

        while (l < r) {
            LL mid = l + r >> 1;
            if (check1(mid, n)) r = mid;
            else l = mid + 1;
        }
        // cout << " r = " << r << endl;
        ans = min(ans, l);
        cout << ans << endl;
    }

    return 0;
}
