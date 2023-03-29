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

int check(int x) {
    int maxv = -1, minv = 9;
    while (x) {
        int t = x % 10;
        maxv = std::max(maxv, t);
        minv = std::min(minv, t);
        x /= 10;
    }
    return maxv - minv;
}

void solve() {
    int l, r;
    std::cin >> l >> r;
    int cnt = -1, ans = 0;
    for (int i = l; i <= std::min(r, l + 100); i++) {
        int t = check(i);
        if (t > cnt) {
            cnt = t;
            ans = i;
        }
    }
    std::cout << ans << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}
