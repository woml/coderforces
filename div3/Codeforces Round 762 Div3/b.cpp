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
        int ans = 0;
        unordered_map<int, int> h;
        for (int i = 1; i * i <= n; i++) {
            if (h[i * i] == 0) {
                ans++;
                h[i * i]++;
            }
        }
        for (int i = 1; i * i * i <= n; i++) {
            if (h[i * i *i] == 0)
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
