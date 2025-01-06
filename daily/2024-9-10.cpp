#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;

void solve(int t) {
    int n, k, m;
    cin >> n >> k >> m;
    string s, p;
    cin >> s;
    int cnt = 0, full = (1 << k) - 1, sum = 0;
    for (int i = 0; i < m; i++) {
        int c = s[i] - 'a';
        cnt |= (1 << c);
        if (cnt == full) {
            sum++;
            p.push_back(s[i]);
            cnt = 0;
        }
    }
    if (sum >= n) {
        cout << "YES\n";
        return;
    } 
    cout << "NO\n";
    for (int i = 0; i < k; i++) {
        if (!(cnt >> i & 1)) {
            cout << p;
            for (int j = p.size(); j < n; j++) {
                char c = 'a' + i;
                cout << c;
            }
            cout << "\n";
            return;
        }
    }
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}