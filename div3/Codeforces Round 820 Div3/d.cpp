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

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            c[i] = b[i] - a[i];
        }
        sort(c.begin(), c.end());

        int l = 0, r = n - 1, ans = 0;
        while (l < r) {
            if (c[l] + c[r] >= 0) {
                ans++;
                r--;
            }
            l++;
        }

        cout << ans << endl;
    }

    return 0;
}
