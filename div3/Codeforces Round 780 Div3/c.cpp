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
        string s;
        int n, sum = 0;
        cin >> s;
        n = s.size();
        vector<int> cnt(26, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int t = s[i] - 'a';
            if (cnt[t] == 0) cnt[t]++, sum++;
            else {
                ans += sum - 1;
                sum = 0;
                for (int j = 0; j < 26; j++) cnt[j] = 0;
            }
            // cout << "i = " << i << " ans = " << ans << " sum = " << sum << endl;
        }
        for (int i = 0; i < 26; i++) ans += cnt[i];
        cout << ans << endl;
    }

    return 0;
}
