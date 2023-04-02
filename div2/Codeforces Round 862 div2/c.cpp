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

void solve() {
    int n, m;
    std:: cin >> n >> m;
    vector<int> lines(n);
    for (int i = 0; i < n; i++) std::cin >> lines[i];
    std::sort(lines.begin(), lines.end());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (lines[mid] < b) l = mid;
            else r = mid - 1;
        }
        if ((LL)(b - lines[l]) * (b - lines[l]) < 4 * (LL)a * c) {
            std::cout << "Yes\n";
            std::cout << lines[l] << "\n";
            continue;;
        }
        if (l + 1 < n && (LL)(b - lines[l + 1]) * (b - lines[l + 1]) < 4 * (LL)a * c) {
            std::cout << "Yes\n";
            std::cout << lines[l + 1] << "\n";
            continue;;
        }
        std::cout << "No\n";
    }
    std::cout << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
