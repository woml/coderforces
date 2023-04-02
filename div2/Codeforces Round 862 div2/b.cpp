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
    string s;
    std::cin >> s;
    char c = s[0];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < c) {
            c = s[i];
            idx = i;
        } else if (s[i] == c) idx = i;
    }
    string t = c + s.substr(0, idx) + s.substr(idx + 1);
    std::cout << t << "\n";
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
