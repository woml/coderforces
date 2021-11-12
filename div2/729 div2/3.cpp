#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 330;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int k, m, n;
        cin >> k >> m >> n;
        int a[N], b[N];
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 1; i <= m; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int i = 1, j = 1;
        bool flag = true;
        vector<int> ans;
        while (i <= m || j <= n) {
            if (i <= m && a[i] == 0) {
                ans.push_back(a[i]);
                i++;
                k++;
            } else if (j <= n && b[j] == 0) {
                ans.push_back(b[j]);
                j++;
                k++;
            } else {
                if ((k < a[i] || i > m) && (k < b[j] || j > n)) {
                    flag = false;
                    break;
                } else if (j <= n && k >= b[j]) {
                    ans.push_back(b[j]);
                    j++;
                } else {
                    ans.push_back(a[i]);
                    i++;
                }
            }
        }
        if (flag) {
            for (int i = 0; i < n + m; i++) cout << ans[i] << " ";
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}