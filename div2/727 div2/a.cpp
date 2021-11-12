#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n, x, t;
        LL ans = 0;
        cin >> n >> x >> t;
        //cout << n << " ";
        int i = n - 1 - t / x;
        if (i <= 0) {
            ans = (LL)n * (n - 1) / 2;
        } else {
            ans = (LL)i * (t / x);
            ans += (LL)(n - i) * (n - i - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}