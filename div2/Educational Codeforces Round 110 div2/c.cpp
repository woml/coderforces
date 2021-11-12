#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;
typedef long long LL;

const int N = 3e5;
LL f[N][2];

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        string s;
        cin >> s;
        int n = s.size();
        LL ans = 0;
        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (s[i] == '?') f[i][0] = f[i][1] = 1;
                else f[i][s[i] - '0'] = 1;
            }
            else {
                if (s[i] == '?') {
                    f[i][0] = f[i - 1][1] + 1;
                    f[i][1] = f[i - 1][0] + 1;
                } else if (s[i] == '0') {
                    f[i][0] = f[i - 1][1] + 1;
                } else 
                    f[i][1] = f[i - 1][0] + 1;
            }
            //cout << "i = " << i << " " << f[i][0] << " " << f[i][1] << endl;
            ans += max(f[i][0], f[i][1]);
        }
        cout << ans << endl;
    }
    return 0;
}