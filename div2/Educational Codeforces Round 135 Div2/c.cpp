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

int len(int x) {
    int res = 0;
    while (x) { res++, x /= 10; }
    return res;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        // cout << len(10000) << endl;
        int n, del = 0, ans = 0;
        cin >> n;
        vector<int> a(n), b(n);
        unordered_map<int, int> st;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st[a[i]]++;
        }
        for (int i = 0; i < n - del; i++) {
            cin >> b[i];
            if (st[b[i]]) {
                st[b[i]]--;
                swap(b[i], b[n - del - 1]);
                del++;
                i--;
            }
        }
        // for (int i = 0; i < n; i++) cout << b[i] << " ";
        // cout << endl;
        // cout << del << endl;
        vector<int> ca(10), cb(10);
        for (int i = 0; i < n; i++) {
            if (st[a[i]] > 0) {
                if (a[i] > 9) {
                    ca[len(a[i])]++;
                    ans++;
                } else {
                    ca[a[i]]++;
                }
                st[a[i]]--;
            }
            if (i < n - del) {
                // cout << "--" << len(b[i]) << endl;
                // cout << ans << " -- ";
                if (b[i] > 9) {
                    ans++;
                    ca[len(b[i])]--;
                } else {
                    ca[b[i]]--;
                }
                // cout << b[i] << " " << ans << endl;
            }
        }
        // cout << ans << endl;
        for (int i = 2; i <= 9; i++) {
            // cout << "ca[" << i << "] = " << ca[i] << endl;
            ans += abs(ca[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
