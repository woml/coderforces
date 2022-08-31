#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        priority_queue<int> q;
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            int r = n - 1 - i, l = i;
            if (s[i] == 'L') {
                ans += l;
                if (r > l) q.push(r - l);
            } else {
                ans += r;
                if (l > r) q.push(l - r);
            }
        }
        for (int k = 1; k <= n; k++) {
            if (!q.empty()) {
                auto t = q.top(); q.pop();
                ans += t;
            } 
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
