#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 1e18;
LL n, k, x;

int solve(LL x, vector<int> &a, LL &ll, vector<int> &b) {
    LL cnt = 0, temp = 1;
    int idx;
    for (int i = a.size() - 1; i >= 0; i--) {
        LL res = a[i] * k + 1;
        temp *= res;
        if (temp < 0 || temp > INF || temp >= x) {
            idx = i;
            ll = temp;
            return i;
        }
        b[i] = temp;
    }
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        string s;
        cin >> n >> k >> x >> s;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int j = i, cnt = 0;
            while (j < n && s[j] == '*') {
                j++;
                cnt++;
            }
            if (cnt > 0) a.push_back(cnt);
            i = j;
        }
        vector<int> b(a.size() + 1);
        b[a.size()] = 1;
        LL cnt = 0;
        int idx = solve(x, a, cnt, b);
    }

    return 0;
}
