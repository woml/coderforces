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
        int n;
        cin >> n;
        unordered_map<int, int> cnt;
        int max_n = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            cnt[arr[i]]++;
            max_n = max(max_n, cnt[arr[i]]);
        }
        int ans = 0;
        while (max_n < n) {
            if (max_n * 2 <= n)
                ans += 1 + max_n;
            else 
                ans += 1 + n - max_n;
            max_n *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}
