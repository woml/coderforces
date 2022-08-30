#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

bool check(int x, vector<int> &a, vector<int> &b) {
    map<int, int> cnt;
    for (auto &t : a) cnt[t & x]++;
    for (auto &t : b) cnt[~t & x]--;

    bool res = true;
    for (auto t : cnt) {
        res &= t.second == 0;
    }
    return res;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int ans = 0;
        for (int bit = 29; bit >= 0; bit--) {
            if (check(ans | (1 << bit), a, b)) {
                ans |= (1 << bit);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
