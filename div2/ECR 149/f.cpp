#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int a[N];
int n, k;

bool check(ll mid) {
    priority_queue<int> pre, suf;
    // [0, i], [i + 1, n - 1]  --> l[i] + r[i + 1]
    vector<int> l(n + 1), r(n + 1);
    ll sum_pre = 0, sum_suf = 0;
    for (int i = 0; i < n; i++) {
        if (sum_pre + a[i] <= mid) {
            pre.push(a[i]);
            sum_pre += a[i];
        } else {
            if (!pre.empty() && pre.top() > a[i]) {
                sum_pre -= pre.top();
                pre.pop();
                pre.push(a[i]);
                sum_pre += a[i];
            }
        }
        l[i] = pre.size();
        if (sum_suf + a[n - 1 - i] <= mid) {
            suf.push(a[n - 1 - i]);
            sum_suf += a[n - 1 - i];
        } else {
            if (!suf.empty() && suf.top() > a[n - 1 - i]) {
                sum_suf -= suf.top();
                suf.pop();
                suf.push(a[n - 1 - i]);
                sum_suf += a[n - 1 - i];
            }
        }
        r[n - 1 - i] = suf.size();
    }
    for (int i = 0; i < n; i++) 
        if (l[i] + r[i + 1] >= k) return true;
    return false;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 1, r = 3e14;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
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
