#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % k == 0) {
        cout << "2\n" << n - 1 << " " << 1 << "\n";
    } else {
        cout << "1\n" << n << "\n";
    }
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
