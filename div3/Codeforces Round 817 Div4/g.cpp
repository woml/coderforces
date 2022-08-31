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
        if (n == 3) cout << "1 2 3" << endl;
        else {
            if (n & 1) {
                cout << "0" << " ";
                n--;
            }
            int odd = 0, even = 0;
            for (int i = 1; i <= n - 2; i++) {
                cout << i << " ";
                if (i & 1) odd ^= i;
                else even ^= i;
            }
            int R = 2147483647 ^ odd;
            cout << "2147483647" << " " << (even ^ R) << endl;
        }
    }

    return 0;
}
