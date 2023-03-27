#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

typedef long long LL;
typedef std::pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), step(n + 1), suf(n + 1), f(n + 1), ans(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = n - 1; i >= 1; i--) {
        int j = a[i] + i + 1;
        step[i] = (j > n || step[j] == -1) ? -1 : step[j] + 1;
        suf[i] = std::max(suf[i + 1], step[i + 1]);
        f[i] = std::max(j > n ? -1 : f[j] + 1, suf[i] + 1);

        if (step[i] == a[i - 1]) ans[i - 1] = 0;
        else if (step[i] != -1 || a[i - 1] <= f[i]) ans[i - 1] = 1;
        else ans[i - 1] = 2;
    }
    for (int i = 0; i < n - 1; i++)
        std::cout << ans[i] << " \n"[i == n - 2];
}

int main(void) {
    int T;
    std::cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}
