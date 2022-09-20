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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1), cnt(k);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            cnt[i % k] = max(cnt[i % k], arr[i]);
        }
        LL sum = 0;
        for (int i = 0; i < k; i++) sum += cnt[i];
        cout << sum << endl;
    }

    return 0;
}
