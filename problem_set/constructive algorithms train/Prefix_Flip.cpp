#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
    int n, flip = 0;
    std::string a, b;
    std::cin >> n >> a >> b;
    int l = 0, r = n - 1;
    std::vector<int> ans;
    for (int i = n - 1; ~i; i--) {
        if (((flip & 1) && a[l] != b[i]) || (!flip && a[r] == b[i])) {
            if (!flip) r--;
            else l++;
            continue;
        }
        if (a[l] == a[r]) {
            ans.push_back(i + 1);
            if (!flip) l++;
            else r--;
            flip ^= 1;
        } else {
            ans.push_back(1);
            ans.push_back(i + 1);
            if (!flip) l++;
            else r--;
            flip ^= 1;
        }
    }
    int m = ans.size();
    std::cout << m << " ";
    if (m == 0) std::cout << "\n";
    for (int i = 0; i < m; i++)
        std::cout << ans[i] << " \n"[i == m - 1];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T -- ) {
        solve();
    }
}