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
        int arr[3][2];
        for (int i = 0; i < 3; i++)
            cin >> arr[i][0] >> arr[i][1];
        int ans = 0;
        if (arr[0][1] && arr[0][1] == arr[1][1] && arr[2][1] < arr[0][1]) {
            ans += abs(arr[1][0] - arr[0][0]);
        } else if (arr[0][1] && arr[0][1] == arr[2][1] && arr[1][1] < arr[0][1]) {
            ans += abs(arr[2][0] - arr[0][0]);
        } else if (arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] > arr[0][1]) {
            ans += abs(arr[2][0] - arr[1][0]);
        }
        cout << ans << endl;
    }

    return 0;
}
