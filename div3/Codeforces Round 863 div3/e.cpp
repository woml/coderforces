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

LL f[18][11];

void init() {
    for (int i = 0; i < 10; i++) if (i != 4) f[0][i] = 1;
    for (int i = 1; i < 18; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 4) continue;
            for (int k = 0; k < 10; k++) {
                if (k == 4) continue;
                f[i][j] += f[i - 1][k];
            }
        }
    }
}

LL dp(LL u) {
    if (!u) return 1;
    vector<int> arr;
    while (u) {
        arr.push_back(u % 10);
        u /= 10;
    }
    LL res = 0, last = 0;
    for (int i = arr.size() - 1; ~i; i--) {
        int x = arr[i];
        for (int j = 0; j < x; j++) {
            res += f[i][j];
        }
        if (x == 4) break;
        if (!i) res++;
    }
    return res;
}

void solve() {
    LL k;
    std::cin >> k;
    LL l = 1, r = 1e18;
    if (k == 1) {
        std::cout << "1\n";
        return;
    }
    while (l < r) {
        LL mid = l + r + 1 >> 1;
        if (dp(mid) - dp(0) < k) l = mid;
        else r = mid - 1;
    }
    std::cout << l + 1 << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    init();
    while (cases -- ) {
        solve();
    }

    return 0;
}
