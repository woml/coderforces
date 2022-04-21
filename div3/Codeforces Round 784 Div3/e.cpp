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
        unordered_map<char, int> first, second;
        unordered_map<string, int> cnt;
        LL ans = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int t = cnt[s];
            cnt[s]++;
            ans += first[s[0]] + (LL)second[s[1]] - (LL)2 * t;
            first[s[0]]++;
            second[s[1]]++;
        }
        cout << ans << endl;
    }

    return 0;
}
