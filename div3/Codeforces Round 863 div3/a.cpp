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
    int n, t;
    std::cin >> n >> t;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' < t) {
            s = s.substr(0, i) + to_string(t) + s.substr(i);
            std::cout << s << "\n";
            return;
        }
    }
    std::cout << s + to_string(t) << "\n";
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
