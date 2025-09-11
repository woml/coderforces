#include <iostream>
#include <vector>

using namespace std;

int solve() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int idx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int maxv = max(arr[idx], arr[i]);
        if (sum - maxv > s) return idx;
        if (arr[idx] < arr[i]) idx = i;
    }
    return sum <= s ? -1 : idx;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        cout << solve() + 1 << "\n";
    }

    return 0;
}