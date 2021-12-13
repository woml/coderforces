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
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        int left = 0;
        LL ans = 0;
        if (abs(arr[0]) >= arr[n - 1]) left = 1;
        if (left == 1) {
            int d = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] < 0) d = i;
            }
            int group = (d + k) / k;
            ans += (LL)arr[0] * (-1);
            for (int i = 2; i <= group; i++) {
                ans += (LL)arr[(i - 1) * k] * (-2);
            }
            for (int i = n - 1; i > d; i -= k) {
                ans += (LL)arr[i] * 2;
            }
        } else {
            int d = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] < 0) d = i;
            }
            int group = (d + k) / k;
            ans += (LL)arr[n - 1];
            for (int i = 1; i <= group; i++) {
                ans += (LL)arr[(i - 1) * k] * (-2);
            }
            for (int i = n - 1 - k; i > d; i -= k) {
                ans += (LL)arr[i] * 2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
