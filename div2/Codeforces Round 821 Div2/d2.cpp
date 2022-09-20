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
const LL INF = 1e18;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) idx.push_back(i);
        }
        if (idx.size() & 1) cout << "-1" << endl;
        else if (idx.size() == 0) cout << "0" << endl;
        else {
            int m = idx.size();
            if (x >= y) {
                if (m == 2) {
                    if (idx[0] + 1 == idx[1]) {
                        cout << min(x, y * 2) << endl;
                    }
                    else cout << y << endl;
                }
                else {
                    cout << (LL)y * m / 2 << endl;
                }
            } else {
                vector<LL> dp(m + 1, INF);
                // cout << m << endl;
                dp[0] = 0;
                // i means the location to be deal with  & loc before i has been solve, dp[i - 1] is the minimum to make a equal to b,i - 2 and so on.
                for (int i = 0; i < m; i += 2) {
                    LL res = 0;
                    // j - 1 has been deal with, but not means the min.
                    // If we have a idx array to be solve like 0, 1, 2, 3, 4, 5. Meantime, i=0, j=5. use x strategy swap from 0 to 5.  1 2 3 4 are changed
                    // twice  which means it still uncomform. we still need swap [1, 2] [3, 4] to make all location change odd times.
                    for (int j = i + 2; j <= m; j += 2) {
                        // res to store the final to make [1, 2] [3, 4] become odd cost.
                        if (j >= i + 4) res += (LL)x * (idx[j - 2] - idx[j - 3]);
                        // find two strategy x, y which is better. X strategy is from i to j - 1 continueously used x. Y strategy is choose i and j - 1,
                        // use y strategy, from i + 1 to j - 2, used x strategy.
                        dp[j] = min(dp[j], dp[i] + res + min((LL)y, (LL)x * (idx[j - 1] - idx[i])));
                    }
                }
                cout << dp[m] << endl;
            }
        }
    }

    return 0;
}
