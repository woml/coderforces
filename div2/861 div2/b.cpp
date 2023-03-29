#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n, m;
    std:: cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    LL ans = 0;
    vector<int> sum(n);
    for (int i = 0; i < m; i++) {
        LL total = 0;
        for (int j = 0; j < n; j++) {
            sum[j] = g[j][i];
            total += g[j][i];
        }
        sort(sum.begin(), sum.end());
        // cout << total << " ";
        for (int j = 0; j < n; j++) {
            total -= sum[j];
            ans += total - (LL)(n - j - 1) * sum[j];
            // cout << "j = " << i << " ans = " << ans << " total = " << total << endl;
        }
        // cout << "i = " << i << " ans = " << ans << " total = " << total << endl;
    }
    std::cout << ans << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) {
        solve();
    }

    return 0;
}
