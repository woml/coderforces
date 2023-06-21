#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;

int d[N], last = 0;

map<int, int> cnt[N];

void solve() {
    int m;
    cin >> m;
    d[1] = 1;
    for (int i = 1; i <= last; i++) cnt[i].clear();

    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        if (op[0] == '+') {

        } else {

        }
    }
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
