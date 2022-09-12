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

        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (c[i] >= 0 && l == -1) l = i;
            if (c[i] > 0 && r == -1) r = i; 
        }
        int ans = 0;
        if (r == -1) {
            if (l != -1)
                ans = n - l >> 1;
            else 
                ans = 0;
        } else {
            int count0 = 0;
            if (l != -1)
                count0 = r - l;
            for (int i = l - 1; i >= 0; i--) {
                
            }
        }

        cout << ans << endl;
    }

    return 0;
}
