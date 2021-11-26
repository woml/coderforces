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
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i ++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), [](int a, int b){
            return a < b;
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= l && arr[i] <= r) {
                if (k >= arr[i]) {
                    k -= arr[i];
                    ans++;
                }
                else break;
            }
            if (arr[i] > r) break;
        }
        cout << ans << endl;
    }

    return 0;
}
