#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    map<string, int> cnt;
    for (int i = 0; i < n - 1; i++) {
        string t = s.substr(i, 2);
        if (!cnt.count(t)) ans++;
        cnt[t] = 1;
    }
    cout << ans << "\n";
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
