#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int N = 1010;

LL q[N];

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        unordered_map<LL, int> m;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
            m[q[i]]++;
        }
        int idx = 0;
        bool flag;
        while (true) {
            flag = false;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int k = abs(q[i] - q[j]);
                    if (m[k] == 0) {
                        q[idx + n] = k;
                        idx++;
                        m[k]++;
                        flag = true;
                    }
                }
            }
            n += idx;
            idx = 0;
            if (n > 300) {
                flag = true;
                break;
            }
            if (!flag) break;
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "yes" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) {
                cout << q[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}