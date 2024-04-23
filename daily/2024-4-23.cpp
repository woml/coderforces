#include <bits/stdc++.h>

using namespace std;

int cnt[200010];

bool solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        for (int j = 0, x; j < k; j++) {
            cin >> x;
            arr[i].push_back(x);
            cnt[x]++;
        }
    }
    for (int i = 0; i < n; i++) {
        bool find = false;
        for (int j = 0; j < arr[i].size(); j++) {
            if (cnt[arr[i][j]] == 1) {
                find = true;
                break;
            }
        }
        if (!find) {
            for (auto x : arr) {
                for (auto v : x) cnt[v]--;
            }
            return true;
        }
    }
    for (auto x : arr) {
        for (auto v : x) cnt[v]--;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T -- ) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}