#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 110;

int q[N];

bool judge(int x) {
    int t = sqrt(x);
    return t * t == x;
}

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        bool f = true;
        for (int i = 1; i <= n; i++) {
            cin >> q[i];
            if (f)
                f = judge(q[i]);
        }
        if (!f) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}