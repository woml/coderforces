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
        int n, x, y;
        cin >> n >> x >> y;
        if (x < y) swap(x, y);
        if (y != 0 || (x + y == 0) || ((n - 1) % x) != 0) cout << "-1" << endl;
        else {
            int now = 1, cnt = 0;
            if (x != 1) {
                for (int i = 1; i < n; i++) {
                    cout << now << " ";
                    cnt++;
                    if (cnt == x) {
                        if (now == 1) now++;
                        now += x;
                        cnt = 0;
                    }
                }
            } else {
                for (int i = 2; i <= n; i++) cout << i << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
