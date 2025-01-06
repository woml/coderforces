#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), cnt(n+2);
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cnt[l]++; cnt[r+1]--;
    }
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i-1];
    long long ans = 0;
    sort(cnt.begin()+1, cnt.begin()+1+n);
    sort(arr.begin(), arr.end());
    for (int i = n; i > 0; i--) {
        ans += (long long)cnt[i]*arr[i-1];
    }
    cout << ans << "\n";
    return 0;
}