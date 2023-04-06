#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int a, b, ans = 2e9;
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    int t = gcd(a, b);
    std::map<int,int> a_cnt;
    

    std::cout << ans << "\n";
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
