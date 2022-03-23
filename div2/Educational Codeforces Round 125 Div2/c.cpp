#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

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
        stack<char> mys;
        cin >> n >> s;
        int ans = 0, now = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') mys.push('(');
            else {
                if (mys.size()) {
                    if (mys.top() == '(') mys.pop();
                    else mys.push(')');
                } else {
                    mys.push(')');
                }
            }
            if (mys.size() == 0) {
                ans++;
                now = i;
            } else {
                if (i - now >= 2 && s[i] == s[now + 1]) {
                    ans++;
                    now = i;
                    while (mys.size()) mys.pop();
                }
            }
        }
        cout << ans << " " << n - now - 1 << endl;
    }

    return 0;
}
