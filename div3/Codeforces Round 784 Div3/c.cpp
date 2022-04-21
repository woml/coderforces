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
        vector<int> arr(110);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool ans = true, is_odd = arr[0] % 2 == 0 ? false : true;
        for (int i = 0; i < n; i += 2) {
            if (is_odd) {
                if (arr[i] % 2 == 0) ans = false;
            } else {
                if (arr[i] & 1) ans = false;
            }
        }
        is_odd = arr[1] % 2 == 0 ? false : true;
        for (int i = 1; i < n; i += 2) {
            if (is_odd) {
                if (arr[i] % 2 == 0) ans = false;
            } else {
                if (arr[i] & 1) ans = false;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
