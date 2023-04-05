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
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    int t1 = std::min(std::min(x1 - 1, n - x1), std::min(y1 - 1, n - y1));
    int t2 = std::min(std::min(x2 - 1, n - x2), std::min(y2 - 1, n - y2));
    // std::cout << t1 << " " << t2 << "\n";
    std::cout << abs(t1 - t2) << "\n";
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
