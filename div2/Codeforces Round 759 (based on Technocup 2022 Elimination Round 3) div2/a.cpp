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
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 1 && arr[i] == 1) ans += 1;
            if (i > 1) {
                if (arr[i] == 0 && arr[i - 1] == 0) {
                    ans = -1;
                    break;
                } else if (arr[i] == 1) {
                    if (arr[i - 1] == 1) ans += 5;
                    else ans += 1;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
