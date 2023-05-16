#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, p[N], f[N];
char a[N], b[N];

void solve() {
    cin >> n >> a;
    int k = 0;
    b[k++] = '$', b[k++] = '#';
    for (int i = 0; i < n; i++) b[k++] = a[i], b[k++] = '#';
    b[k++] = '^';
    n = k;
    for (int i = 1; i <= n; i++) f[i] = 0;
    int mr = 0, mid;
    stack<int> stk;
    for (int i = 1; i < n; i++) {
        if (i < mr) p[i] = min(mr - i, p[mid * 2 - i]);
        else p[i] = 1;
        while (b[p[i] + i] == b[i - p[i]]) p[i]++;
        if (i + p[i] > mr) {
            mr = i + p[i];
            mid = i;
        }
        if (i & 1) {
            stk.push(i);
        } else {
            while (!stk.empty()) {
                auto t = stk.top();
                if (t + p[t] <= i) stk.pop();
                else {
                    f[i] = f[2 * t - i - 2] + 1;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 2; i < n; i += 2) {
        ans += f[i];
    }
    cout << ans << "\n";
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
