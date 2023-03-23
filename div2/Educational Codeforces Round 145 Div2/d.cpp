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
const LL INF = 1e18, ADD = 1e12 + 1;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        string s;
        cin >> s;
        s = ' ' + s + '1';
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 1; i <= n; i++) if (s[i] == '0') r++;
        LL ans = r * ADD;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') l++;
            else r--;
            if (s[i] == '1' && s[i + 1] == '0') 
                ans = min(ans, (l + r - 2) * ADD + ADD - 1);
            else
                ans = min(ans, (l + r) * ADD);
        }
        cout << ans << endl;
    }
    return 0;
}
