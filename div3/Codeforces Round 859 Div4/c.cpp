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
        string s;
        cin >> n >> s;
        vector<int> cnt(26);
        cnt[s[0] - 'a'] = 1;
        bool ans = true;
        for (int i = 1; i < n; i++) {
            int t = s[i] - 'a';
            if (cnt[t] != 0) {
                if (cnt[t] == cnt[s[i - 1] - 'a']) {
                    ans = false;
                    break;
                }
            } else cnt[t] = 3 - cnt[s[i - 1] - 'a'];
            int k;
            if (i + 1 < n) {
                k = s[i + 1] - 'a';
                if (cnt[t] == cnt[s[i + 1] - 'a']) {
                    ans = false;
                    break;
                } 
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
