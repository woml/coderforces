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

int arr[N], cnt[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            if (arr[i] <= n) cnt[arr[i]]++;
        }
        sort(arr + 1, arr + 1 + n);
        int ans = 0, idx = 1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                int j = i * 2 + 1;
                bool find = true;
                for (; idx <= n + 2; idx++) {
                    if (idx == n + 1) {
                        find = false;
                        break;
                    }
                    if (arr[idx] <= n) {
                        if (cnt[arr[idx]] > 1 && arr[idx] >= j) {
                            cnt[arr[idx]]--;
                            if(cnt[arr[idx]] == 1) idx++;
                            break;
                        }
                    } else if (arr[idx] >= j) {
                        idx++;
                        break;
                    }
                }
                if (!find) {
                    ans = -1;
                    break;
                }
                ans++;
            } else if (cnt[i] > 1) {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
