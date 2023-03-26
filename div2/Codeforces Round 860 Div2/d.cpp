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
        scanf("%d", &n);
        vector<int> arr(n), ans(n);
        LL sum = 0;
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]), sum += arr[i];
        sort(arr.begin(), arr.end());
        int t = arr[n - 1] - arr[0];
        if (abs(sum) >= t) {
            printf("No\n");
        } else {
            printf("Yes\n");
            if (sum <= 0) {
                LL pre = 0;
                for (int i = 0, l = 0, r = n - 1; i < n; i++, l++) {
                    ans[i] = arr[l];
                    pre += arr[l];
                    while (l < r && i < n && pre + arr[r] <= 0) {
                        ans[++i] = arr[r];
                        pre += arr[r --];
                    }
                }
                for (int i = 0; i < n; i++) printf("%d ", ans[i]);
                printf("\n");
            } else {
                LL pre = 0;
                for (int i = 0, l = 0, r = n - 1; i < n; i++, r--) {
                    ans[i] = arr[r];
                    pre += arr[r];
                    while (l < r && i < n && pre + arr[l] >= 0) {
                        ans[++i] = arr[l];
                        pre += arr[l++];
                    }
                }
                for (int i = 0; i < n; i++) printf("%d ", ans[i]);
                printf("\n");
            }
        }
    }

    return 0;
}
