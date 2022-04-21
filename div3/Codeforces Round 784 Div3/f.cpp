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
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum[i] += sum[i - 1] + arr[i];
        }
        int idx = 1, now = arr[1];
        while (now < sum[n] / 2) {
            idx++;
            now += arr[idx];
        }
        int ans = 0;
        // cout << idx << endl;
        for (; idx >= 0; idx--) {
            int l = idx + 1, r = n;
            bool find = false;
            while (l < r) {
                int mid = l + r >> 1;
                int t = sum[n] - sum[mid - 1];
                // cout << idx << " " << l << " " << r << " " << t << endl;
                if (t == sum[idx]) {
                    find = true;
                    l = r = mid;
                    break;
                } else if (t > sum[idx]) l = mid + 1;
                else r = mid - 1;
            }
            if (sum[idx] == sum[n] - sum[l - 1]) find = true;
            // cout << sum[idx] << " " << l << " " << r << endl;
            if (find) {
                ans = idx + n - l + 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
