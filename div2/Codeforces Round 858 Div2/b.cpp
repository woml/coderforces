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
        int n, cnt = 0;
        cin >> n;
        vector<int> arr(n);
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> arr[i];
            hash[arr[i]]++;
        }

        if (hash[0] <= n - hash[0] + 1) {
            cout << 0 << endl;
        } else if (hash[1] > 0 && hash[0] + hash[1] == n) {
            cout << 2 << endl;
        } else cout << 1 << endl;
    }

    return 0;
}
