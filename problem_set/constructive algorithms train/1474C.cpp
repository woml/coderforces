#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

const int N = 1e5 + 10;

void solve() {
    int n;
    std::cin >> n;
    n *= 2;
    std::multiset<int> cnt;
    std::vector<int> arr(n), ans(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i], cnt.insert(arr[i]);
    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
        int x = arr[i] + arr[n - 1], t = x, idx = 0;
        while (!cnt.empty()) {
            int r = *cnt.rbegin();
            if (cnt.count(t - r)) {
                ans[idx * 2] = t - r;
                ans[idx++ * 2 + 1] = r;
                cnt.erase(cnt.find(r));
                if (cnt.find(t - r) == cnt.end()) break;
                cnt.erase(cnt.find(t - r));
                t = r;
            } else break;
        }
        if (!cnt.empty()) {
            cnt.clear();
            for (int j = 0; j < n; j++) cnt.insert(arr[j]);
        }
        else {
            std::cout << "Yes\n";
            std::cout << x << "\n";
            for (int i = 0; i < n / 2; i++)
                std::cout << ans[i * 2] << " " << ans[i * 2 + 1] << "\n";
            return;
        }
    }
    std::cout << "No\n";
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