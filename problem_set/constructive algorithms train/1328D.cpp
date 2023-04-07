#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

const int N = 1e5 + 10;
std::vector<int> primes;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n), ans(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    ans[0] = 1;
    int cnt = 1, idx = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) ans[i] = ans[i - 1], idx = i;
        else ans[i] = 3 - ans[i - 1], cnt = 2;
    }
    if (arr[0] != arr[n - 1] && ans[0] == ans[n - 1]) {
        if (idx != -1) {
            for (int i = idx; i < n; i++) ans[i] = 3 - ans[i];
        } else {
            ans[n - 1] = 3;
            cnt++;
        }
    }
    std::cout << cnt << "\n";
    for (int i = 0; i < n; i++) std::cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }
}