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
        vector<int> cnt(100, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'A']++;
        }
        if (n == 5 && cnt['T' - 'A'] == 1 && cnt['i' - 'A'] == 1 && cnt['m' - 'A'] == 1 && cnt['u' - 'A'] == 1 && cnt['r' - 'A'] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
