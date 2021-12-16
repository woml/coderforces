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
string s[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        string ans;
        for (int i = 0; i < n - 2; i++) {
            cin >> s[i];
        }
        ans += s[0];
        for (int i = 1; i < n - 2; i++) {
            if (s[i - 1][1] != s[i][0]) {
                ans.push_back(s[i][0]);
            } 
            ans.push_back(s[i][1]);
        }
        if (ans.size() != n) ans.push_back('a');
        cout << ans << endl;
    }

    return 0;
}
