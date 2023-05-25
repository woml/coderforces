#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') l++;
        else r++;
    }
    if (n & 1 || l != r) {
        cout << "-1\n";
    } else {
        stack<int> stk, rstk;
        int now = 1;
        for (int i = 0; i < n; i++) {
            if (now & 1) {
                if (s[i] == '(') {
                    stk.push(i);
                    ans[i] = now;
                } else {
                    if (!stk.empty()) {
                        stk.pop();
                        ans[i] = now;
                    } else {
                        now = 3 - now;
                        rstk.push(i);
                        ans[i] = now;
                    }
                }
            } else {
                if (s[i] == ')') {
                    rstk.push(i);
                    ans[i] = now;
                } else {
                    if (!rstk.empty()) {
                        rstk.pop();
                        ans[i] = now;
                    } else {
                        now = 3 - now;
                        stk.push(i);
                        ans[i] = now;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 1) cnt |= 1;
            else cnt |= 2;
        }
        if (cnt == 3) cnt = 2;
        else cnt = 1;
        cout << cnt << "\n";
        if (cnt == 1) {
            for (int i = 0; i < n; i++) {
                cout << 1 << " \n"[i == n - 1];
            }
        } else {
            for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
        }
        
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
