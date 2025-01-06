#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

void solve(int x) {
    int n, m, low;
    cin >> n >> m >> low;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long ans = -1;
    vector<vector<long long>> betw;
    long long sum = 0;
    for (int i = 0, l = 0; i < n; i++) {
        sum += arr[i];
        if (sum >= low && betw.size() < m) {
            betw.push_back({l, i, sum});
            l = i+1;
            sum = 0;
        }
    }
    if (betw.size() < m) {
        cout << "-1\n";
        return;
    }
    ans = sum;
    long long t = 0;
    for (int i = n-1; i >= 0 && betw.size() > 0; i--) {
        t += arr[i];
        if (t >= low) {
            sum = sum - t + betw.back()[2];
            betw.pop_back();
            t = 0;
            ans = max(ans, sum);
        }
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    return 0;
}