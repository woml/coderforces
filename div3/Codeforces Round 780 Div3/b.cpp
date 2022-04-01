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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (n == 1) {
            if (arr[0] == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (arr[n - 1] - arr[n - 2] > 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }

    return 0;
}
