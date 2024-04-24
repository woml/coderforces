#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> arr(n, vector<array<int, 2>>(32));
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 31; ~j; j--) {
            arr[i][j][0] = x >> j & 1;
            arr[i][j][1] = j;
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int add = 0, l = -1, r = -1;
        bool low = false;
        for (int j = 31; ~j; j--) {
            if (arr[i - 1][j][0] == 1) {
                l = max(l, j);
            }
            if (arr[i][j][0] == 1) {
                r = max(r, j);
            }
        }
        if (arr[i][r][1] > arr[i - 1][l][1]) continue;
        add += arr[i - 1][l][1] - arr[i][r][1];
        for (;l >= 0; r--, l--) {
            if (r >= 0) {
                if (arr[i][r][0] < arr[i - 1][l][0]) {
                    low = true;
                    break;
                } else if (arr[i][r][0] > arr[i - 1][l][0]) {
                    break;
                }
            } else if (r < 0 && arr[i - 1][l][0]) {
                low = true;
                break;
            } 
        }
        ans += add + low;
        for (int j = 31; ~j; j--) {
            arr[i][j][1] += add + low;
        }
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) solve();
    return 0;
}