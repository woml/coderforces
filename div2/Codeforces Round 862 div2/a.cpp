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
    int n;
    std::cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int r = 1 << 8;
    for (int l = 0; l < r; l++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum ^= (l ^ arr[i]);
            // std::cout << "sum = " << sum << " ";
        }
        // std::cout << "\n";
        if (sum == 0) {
            std::cout << l << "\n";
            return;
        }
    }
    std::cout << "-1\n";
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
