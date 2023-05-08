#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
string s;

bool check(int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return true;
        l++, r--;
    }
    return false;
}

void solve() {
    cin >> s;
    int n = s.size();
    for (int i = n - 1; i; i--) {
        for (int j = 0; j + i - 1 < n; j++) {
            if (check(j, j + i - 1)) {
                cout << i << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) {
        solve();
    }
    return 0;
}