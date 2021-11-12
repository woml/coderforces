#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10, MOD = 1e9 + 7;

int main(void) {   
    int T;
    cin >> T;
    while (T --) {
        int n, k;
        cin >> n >> k;
        LL ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * n % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}