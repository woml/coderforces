#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string ans;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && s[j] != s[i]) j++;
        ans.push_back(s[i]);
        i = j;
    }
    cout << ans << "\n";
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
