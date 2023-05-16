#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << i * 2 << " \n"[i == n];
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
