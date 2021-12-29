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
int n, m, rb, cb, rd, cd;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int x = 1, y = 1;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        int ans = 0;
        for (; ; ans++) {
            if (rb == rd || cd == cb) break;
            int t1 = rb + x, t2 = cb + y;
            if (t1 < 0 || t1 > n) x = -x;
            if (t2 < 0 || t2 > m) y = -y;
            rb += x;
            cb += y;
            // cout << rb << " " << cb << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
