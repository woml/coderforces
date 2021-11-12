#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110, M = 2e5;

int q[N], sum, f[M];
int n;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool judge() {
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = M; j >= q[i]; j--)
            f[j] = max(f[j], f[j - q[i]]);
    return f[sum / 2] != 0;
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
    }

    int max_gcd = q[1];
    for (int i = 1; i <= n; i++) {
        max_gcd = gcd(max_gcd, q[i]);
    }
    for (int i = 1; i <= n; i++) {
        q[i] /= max_gcd;
        sum += q[i];
    }
    if (sum & 1) cout << "0" << endl;
    else if (judge()) {
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if ((q[i] & 1) && ans == -1) ans = i; 
        }
        cout << "1" << endl;
        cout << ans << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}