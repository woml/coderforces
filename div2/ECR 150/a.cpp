#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    if (n > 4) cout << "Alice\n";
    else cout << "Bob\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
