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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // find d_min
        for (int i = 0; i < n; i++) {
            int t = a[i], l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (b[mid] >= t) r = mid;
                else l = mid + 1;
            }
            cout << b[l] - t << " ";
        }
        cout << endl;

        // find d_max
        int last = n - 1;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(b[last] - a[i]);
            if (i > 0 && a[i] > b[i - 1]) last = i - 1;
        }
        for (int i = n - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
