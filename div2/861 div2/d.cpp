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

void solve() {
    int n, k;
    LL ans = 0;
    std::cin >> n >> k;
    unordered_map<int, int> odd, even;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        if (arr[i] == 2) std::cout << "loc[" << i << "] = 2" << endl;
    }
    for (int i = n; i; i--) {
        if (i + k <= n) {
            int j = i + k;
            if (j & 1) odd[arr[j]]--;
            else even[arr[j]]--;
        }
        if (i >= k / 2 && i + k - 1 <= n) {
            int t = (i & 1) ? odd[arr[i]] : even[arr[i]];
            ans += k / 2 - t;
        }else if (i < k / 2 && i + k - 1 <= n) {
            int t = (i & 1) ? odd[arr[i]] : even[arr[i]];
            int l = (n - k) / 2 + 1;
            cout << "<-- t = " << t << " l = " << l << " --> ";
            ans += min(i, l) - t;
            if (i & 1) {
                int j = i + k - 1;
                if (j <= n) odd[arr[j]]--;
                odd[arr[j - 2 * i + 2]]--;
            } else {
                int j = i + k - 1;
                if(j <= n) even[arr[j]]--;
                even[arr[j - 2 * i + 2]]--;
            }
        } else if (i + k / 2 < n && i > k / 2) {
            if (i + k - 1 <= n) {
                int t = (i & 1) ? odd[arr[i]] : even[arr[i]];
                ans += (n - i) / 2 - t;
            } else {
                int mid = n - k / 2 + 1, j = mid + mid - i;
                if (arr[j] != arr[i]) {
                    // cout << "<--i = " << i << " j = " << j << " -->";
                    ans++;
                }
            }
        } 
        cout << "i = " << i << " ans = " << ans << " " << odd[arr[i]] << " " << even[arr[i]] << endl;
        if (i >= k + 1 - k / 2) {
            if (i & 1) odd[arr[i]]++;
            else even[arr[i]]++;
        }
    }
    std:: cout << ans << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
