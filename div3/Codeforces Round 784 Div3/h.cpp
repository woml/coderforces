#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int arr[N];

int main(void) {
    int T;
    cin >> T;
    vector<int> v(31);
    v[0] = 1;
    for (int i = 1; i < 31; i++) {
        v[i] = v[i - 1] * 2;
    }
    while (T -- ) {
        int n, k;
        vector<int> cnt(31, 0);
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            int x = arr[i], idx = 0;
            while (x) {
                cnt[idx++] += x & 1;
                x >>= 1;
            }
        }
        for (int i = 30; i >= 0; i--) {
            int diff = n - cnt[i];
            if (k >= diff) {
                cnt[i] = n;
                k -= diff;
            }
        }
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            if (cnt[i] == n) ans += v[i];
        }
        cout << ans << endl;
    }

    return 0;
}
