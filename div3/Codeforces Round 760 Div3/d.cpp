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

int arr[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        int left = n - k * 2;
        int ans = 0;
        for (int i = 0; i < left; i++) ans += arr[i];
        for (int i = left, j = left + k; j < n; i ++, j ++) {
            if (arr[i] == arr[j]) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
