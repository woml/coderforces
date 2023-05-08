#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

void solve() {
    int n, m, cnt1 = 0, cnt2 = 0;
    cin >> n >> m;
    vector<int> sum(m + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0) sum[x] = 1;
        else if (x == -1) cnt1++;
        else cnt2++;
    }
    for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
    
    int ans = max(cnt1, cnt2) + sum[m];
    for (int i = 1; i <= m; i++) {
        if (sum[i] - sum[i - 1] > 0) {
            int l = min(sum[i - 1] + cnt1, i - 1);
            int r = min(sum[m] - sum[i] + cnt2, m - i);
            ans = max(ans, l + r + 1);
        }
    }
    cout << min(ans, m) << "\n";
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