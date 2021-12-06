#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e5 + 10;

int arr[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++) cin >> arr[i];
        sort(arr + 1, arr + k + 1, [](int a, int b){
            return a > b;
        });
        int t = arr[1], j = 2;
        int ans = 1;
        while (t) {
            if (j <= k && t > n - arr[j]) {
                ans++;
                t -= n - arr[j++];
            } else break;
        }
        cout << ans << endl;
    }

    return 0;
}
