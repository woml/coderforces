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
const LL INF = 1e18, ADD = 1e12;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<LL>> f(2, vector<LL>(2, INF));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                f[i & 1][1] = min(f[1 - (i & 1)][0], f[1 - (i & 1)][1]);
                f[i & 1][0] = f[1 - (i & 1)][0] + ADD + 1;
            } else {
                f[i & 1][0] = f[1 - (i & 1)][0];
                f[i & 1][1] = f[1 - (i & 1)][1] + ADD + 1;
                // if (i != 1 && s[i - 2] == '1')
                //     f[i & 1][1] = min(f[i & 1][1], f[1 - (i & 1)][1] + ADD);
            }
            printf("f[%d][1] = %lld  ", i, f[i & 1][1]);
            printf("f[%d][0] = %lld\n", i, f[i & 1][0]);
        }
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt++;
            if (i + 1 < n && s[i] == '1' && s[i + 1] == '0') {
                if (cnt == 1) flag = true;
                break;
            }
        }
        cout << min(f[n & 1][0], f[n & 1][1]) - flag << endl;
    }

    return 0;
}
