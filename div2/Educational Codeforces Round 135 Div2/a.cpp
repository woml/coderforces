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
        vector<PII> arr(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr[i] = {x, i + 1};
        }
        sort(arr.begin(), arr.end());
        cout << arr[n - 1].second << endl;
    }

    return 0;
}
