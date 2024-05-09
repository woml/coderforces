#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    string t;
    int n;
    cin >> t >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int m = t.size();
    typedef pair<int,int> pii;
    vector<vector<pair<int,int>>> r(m);
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            string s = arr[j - 1];
            int p = s.size();
            if (i + p <= m && t.substr(i, p) == s) {
                r[i].push_back({p, j});
            }
        }
        sort(r[i].begin(), r[i].end(), [](pii &a, pii &b) {
            return a.first > b.first;
        });
    }
    vector<pair<int,int>> ans;
    int max_r = -1;
    pair<int, int> maxv = {-1, -1};

    for (int i = 0; i < m; i++) {
        if (i > max_r) {
            if (r[i].size() == 0 && (maxv.first == -1 || maxv.second + arr[maxv.first - 1].size() - 1 <= max_r)) {
                cout << "-1\n";
                return;
            }
            if (r[i].size() != 0 && (maxv.first == -1 || i + r[i][0].first > arr[maxv.first - 1].size() + maxv.second)) {
                maxv = {r[i][0].second, i};
            }
            ans.push_back(maxv);
            max_r = arr[maxv.first - 1].size() + maxv.second - 1;
            maxv = {-1, -1};
        } else {
            if (r[i].size() > 0) {
                if (maxv.first == -1 || i + r[i][0].first > arr[maxv.first - 1].size() + maxv.second) {
                    maxv = {r[i][0].second, i};
                }
            }
        }
        // maxv --> {rank, loc}
        // cout << "i = " << i << " " << ans.size() << " " << max_r << " | " << maxv.first << " " << maxv.second  << "\n";
    }

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x.first << " " << x.second + 1 << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T --) solve();
    return 0;
}