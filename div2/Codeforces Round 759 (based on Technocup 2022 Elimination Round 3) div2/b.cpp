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
        int maxv = -1, max_idx = -1;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) {
            if (max_idx == -1) {
                max_idx = i;
                maxv = arr[i];
            } else if (maxv <= arr[i]) {
                max_idx = i;
                maxv = arr[i];
            }
        }
        int ans = 0, j = n - 1, now = arr[n - 1];
        while (j != max_idx) {
            while (j >= 0 && arr[j - 1] <= now) j--;
            ans++;
            j--;
            now = arr[j];
        }
        cout << ans << endl;
    }

    return 0;
}
