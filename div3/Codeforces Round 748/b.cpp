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
        LL n;
        cin >> n;
        int ans = 1e9;
        // 00 25 50 75
        string s[4] = {"00", "52", "05", "57"};
        string t = to_string(n);
        reverse(t.begin(), t.end());
        int m = t.size();
        for (int i = 0; i < 4; i++) {
            int j = 0, d = 0;
            while (j < m && t[j] != s[i][d]) j++;
            if (j == m) continue;
            j++;
            d++;
            while (j < m && t[j] != s[i][d]) j++;
            //out << j << endl;
            ans = min(ans, j);
        }
        cout << ans - 1 << endl;
    }

    return 0;
}
