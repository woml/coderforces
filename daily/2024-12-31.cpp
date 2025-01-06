#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> cntN(26, -1), cntM(26, -1);
    for (int i = 1; i < n; i++) {
        int c = s[i]-'a';
        if (cntN[c] == -1) cntN[c] = i;
    }
    for (int i = m-2; i >= 0; i--) {
        int c = t[i]-'a';
        if (cntM[c] == -1) cntM[c] = i;
    }
    int ans = 1e9, idx = -1;
    for (int i = 0; i < 26; i++) {
        if (cntN[i]  == -1 || cntM[i] == -1) continue;
        int d = cntN[i]+1+m-1-cntM[i];
        if (d < ans) {
            ans = d;
            idx = i;
        }
    }
    if (ans == 1e9) cout << "-1\n";
    else {
        cout << s.substr(0, cntN[idx]) << t.substr(cntM[idx]) << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}