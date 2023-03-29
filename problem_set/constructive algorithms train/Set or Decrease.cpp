#include <iostream>
#include <algorithm>
#include <vector>

typedef long long LL;

bool check(LL steps, std::vector<LL>& sum, LL k, int n) {
    if (sum[n] <= k) return true;
    LL s1 = 0, s2 = 0, t = 1e18;
    if (steps >= n) s1 = n - 1, s2 = steps - n + 1;
    else s1 = steps, s2 = 0;

    for (; s1 >= 0; s1--, s2++) {
        LL temp = sum[n - s1] - sum[1] + (sum[1] - s2) * (s1 + 1);
        t = std::min(t, temp);
    }

    return t <= k;
}

void solve() {
    int n;
    LL k;
    std::cin >> n >> k;
    std::vector<LL> arr(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> arr[i];
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) sum[i] += sum[i - 1] + arr[i];
    LL l = 0, r = 1e15;
    while (l < r) {
        LL mid = l + r >> 1;
        if (check(mid, sum, k, n)) r = mid;
        else l = mid + 1;
    }
    std::cout << l << std::endl;
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