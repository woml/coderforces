#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10, mod = 1e9 + 7;



int quick_mod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int m, n;
    cin >> n >> m;
    map<int, int> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (!s.count(arr[i])) s[arr[i]] = 1;
        else s[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    n = arr.size();
    int l = 0, v = 1, ans = 0;
    for (int r = 0; r < n; r++) {
        while (arr[r] - arr[l] >= m) {
            v = (ll)v * quick_mod(s[arr[l]], mod - 2) % mod;
            l++;
        }
        v = (ll)s[arr[r]] * v % mod;
        if (r - l + 1 >= m) {
            ans = (ans + v) % mod;
        }
    }
    cout << ans << "\n";
    // for (int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}