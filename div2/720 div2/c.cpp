#include <iostream>
#include <vector>

using namespace std;

const int N = 1e4 + 10;
vector<int> ans(N);
int n;

int query1(int i, int j) {
    cout << "? 1 " << i << " " << j << " " << n - 1 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int query2(int i, int j) {
    cout << "? 2 " << i << " " << j << " 1" << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve() {
    cin >> n;
    int max_r;
    ans.clear();
    max_r = n;
    ans[n] = n;
    for (int i = 1; i + 1 <= n; i += 2) {
        int cur = query1(i, i + 1);
        if (cur == n) {
            ans[i + 1] = n;
            max_r = i + 1;
        } else if (cur == n - 1) {
            cur = query1(i + 1, i);
            if (cur == n) ans[i] = n, max_r = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == max_r) continue;
        ans[i] = query2(i, max_r);
    }
    cout << "! ";
    for (int i = 1; i <= n; i ++ ) cout << ans[i] << " ";
    cout << endl;
    cout.flush();
}

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }

    return 0;
}