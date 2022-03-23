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
        int n, B, x, y;
        cin >> n >> B >> x >> y;
        vector<int> arr(n + 10, 0);
        LL sum = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i - 1] + x <= B) {
                arr[i] = arr[i - 1] + x;
            } else {
                arr[i] = arr[i - 1] - y;
            }
            sum += arr[i];
        }
        cout << sum << endl;
    }

    return 0;
}
