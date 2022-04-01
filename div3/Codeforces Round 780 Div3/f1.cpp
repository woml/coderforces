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
        vector<int> cnt_plus(n + 10), cnt_minus(n + 10);
        vector<int> conti_minus(n + 10);
        for (int i = 1; i <= n; i++) {
            char c = s[i - 1];
            if (c == '+') cnt_plus[i]++;
            else cnt_minus[i]++;
            cnt_minus[i] += cnt_minus[i - 1];
            cnt_plus[i] += cnt_plus[i - 1];
            if (s[i - 1] == '-') conti_minus[i] = 1;
        } 
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '-' && s[i - 2] == '-') conti_minus[i] += conti_minus[i - 1];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool flag = false;
            if (conti_minus[i] > 0 && conti_minus[i] % 2 == 0) flag = true;
            int conti_j = 0;
            for (int j = i + 1; j <= n; j++) {
                int plus = cnt_plus[j] - cnt_plus[i - 1];
                int minus = cnt_minus[j] - cnt_minus[i - 1];
                if (s[j - 1] == '+') flag = false;
                if (plus == minus) {
                    ans++;
                } else {
                    if (!flag) {
                        if (conti_minus[j] > 0 && conti_minus[j] % 2 == 0) conti_j++;
                    } else {
                        if (conti_minus[j] > 0 && conti_minus[j] & 1) conti_j++;
                    }
                    // if (i == 2 && j == 4) cout << conti_minus[j] << endl;
                    int l = minus - plus;
                    if (minus > plus && l % 3 == 0 && conti_j >= l / 3) ans++;
                    // cout << "i = " << i << " j = " << j << " plus = " << plus << " minus = " << minus << " " << conti_j << " ans = " << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
