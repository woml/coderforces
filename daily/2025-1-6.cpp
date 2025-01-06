#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string myUnion(string s, string t) {
    int n = s.size(), m = t.size();
    string res;
    for (int i = m - 1; i >= 0; i--) {
        if (t[i] == s[i+n-m]) res.push_back('0');
        else res.push_back('1');
    }
    for (int i = n - m - 1; i >= 0; i--) res.push_back(s[i]);
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int idx = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            idx = i;
            break;
        }
    }
    cout << "1 " << n << " ";
    if (idx == -1) cout << "1 1\n";
    else {
        int len = n - idx, loc = -1;
        string sMax = "";
        for (int l = 0; l + len - 1 < n; l++) {
            string t = s.substr(l, len);
            auto p = myUnion(s, t);
            // cout << l << " " << p << "\n";
            if (p > sMax) {
                sMax = p;
                loc = l;
            }
        }
        cout << loc + 1 << " " << loc + len << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) solve();
    return 0;
}