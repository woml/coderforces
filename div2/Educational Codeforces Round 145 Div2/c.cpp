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
        int n, k, idx;
        cin >> n >> k;
        for (int i = 1; ; i++) {
            if (k < i) {
                idx = i;
                break;
            }
            k -= i;
        }
        for (int i = 1; i < idx; i++) cout << "2 ";
        if (idx <= n) {
            cout << 1 + 2 * k - 2 * idx << " ";
        }
        for (int i = idx + 1; i <= n; i++) cout << "-1000 ";
        cout << endl;
    }

    return 0;
}
