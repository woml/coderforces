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
    vector<int> b(n), a(n + 1);
    for (int i = 1; i < n; i++) std::cin >> b[i];
    a[0] = b[1];
    for (int i = 1; i < n ; i++) {
        a[i] = b[i];
    }
    for (int i = 1; i < n; i++) {
        if (std::max(a[i], a[i - 1]) != b[i]) {
            // std::cout << a[i] << " " << b[i] << "\n";
            a[i - 1] = b[i];
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
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
