#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

void solve() {
    vector<int> arr;
    int n, m, ans = 0, tot;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    tot = n * m;
    sort(arr.begin(), arr.end());

    // max left upper 
    int t = arr[tot - 1] * (tot - 1);
    t -= (tot - min(n, m)) * arr[0] + (min(n, m) - 1) * arr[1];
    ans = t;
    t = -arr[0] * (tot - 1);
    t += (tot - min(n, m)) * arr[tot - 1] + (min(n, m) - 1) * arr[tot - 2];
    ans = max(ans, t);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) {
        solve();
    }
    return 0;
}