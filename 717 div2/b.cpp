#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2020;

int s[N], rs[N], q[N];

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> q[i];
            s[i] = s[i - 1]^q[i];
        }
        for (int i = n; i >= 1; i--)
            rs[i] = rs[i + 1]^q[i];
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (s[i] == rs[i + 1]) flag = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == rs[j + 1] && rs[j + 1] == (s[j] ^ s[i])) flag = true;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}