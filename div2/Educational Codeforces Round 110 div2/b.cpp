#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <unordered_map>


using namespace std;
typedef long long LL;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

const int N = 2020;
int q[N];

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        int idx = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x & 1) q[idx++] = x;
        }
        //even
        for (int i = idx; i < n; i++) {
            ans += i;
        }
        //odd
        for (int i = 0; i < idx; i++) {
            for (int j = i + 1; j < idx; j++)
                if (gcd(q[i], q[j] * 2) > 1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}