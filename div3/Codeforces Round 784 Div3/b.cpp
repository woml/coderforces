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
        cin >> n;
        unordered_map<int, int> cnt;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if (ans == -1 && cnt[x] >= 3) {
                ans = x;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
