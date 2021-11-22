#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6;

LL cnt(LL n, LL k) {
    if (k <= n) {
        return (k + 1) * k / 2;
    } else {
        int t = 2 * n - 1;
        return n * n - (t - k + 1) * (t - k) / 2;
    }
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        LL k, x;
        cin >> k >> x;
        LL t = k * 2 - 1;
        LL l = 1, r = t;
        while (l < r) {
            LL mid = l + r >> 1;
            if (cnt(k, mid) >= x) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}