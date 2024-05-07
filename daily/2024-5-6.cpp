#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int T;

void solve(int x) {
    ll a, b;
    cin >> a >> b;
    vector<int> arr;
    for (int i = 0; b; i++) {
        arr.push_back(b);
        b /= 5;
    }
    int cnt2 = 0, cnt5 = 0;
    while (a % 2 == 0) {
        cnt2++;
        a /= 2;
    }
    while (a % 5 == 0) {
        cnt5++;
        a /= 5;
    }
    ll ans = 0;
    for (int i = cnt5 + arr.size() - 1; i >= 0 && ans == 0; i--) {
        int t = pow(2, max(i - cnt2, 0));
        t = arr[max(i - cnt5, 0)] / t * t;
        ans = max(ans, (ll)t * a * (ll)pow(2, cnt2) * (ll)pow(5, cnt5) * (ll)pow(5, max(i - cnt5, 0)));
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}