#include <iostream>

using namespace std;

const int N = 110;
int a[N];

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        int q = 100000;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            q = min(q, a[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > q) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}