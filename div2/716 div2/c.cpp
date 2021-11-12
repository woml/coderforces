#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
bool st[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int n;
    cin >> n;
    LL ans = 1;
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (gcd(i, n) == 1) {
            st[i] = true;
            ans = ans * i % n;
            cnt++;
        }
    }
    if (ans != 1) {
        cnt--;
        st[ans] = false;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n - 1; i++) 
        if (st[i]) cout << i << " ";
    cout << endl;
    return 0;
}