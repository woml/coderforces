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
        string a, s, b;
        cin >> a >> s;
        int i = a.size() - 1, j = s.size() - 1;
        bool flag = true;
        for (; ~j;j--, i--) {
            int x, y = s[j] - '0';
            if (i >= 0) x = a[i] - '0';
            else x = 0;
                if (y < x) {
                    y = (s[--j] - '0') * 10 + y;
                }
                if (y < x || y - x > 9) {
                    flag = false;
                    break;
                }
                string t = to_string(y - x);
                reverse(t.begin(), t.end());
                b += t;
            //}
        }
        if (i >= 0) flag = false;
        if (flag) {
            // cout << b << endl;
            while (b.size() && b.back() == '0') b.pop_back();
            reverse(b.begin(), b.end());
            cout << b << endl;
        }
        else cout << "-1" << endl;
    }

    return 0;
}
