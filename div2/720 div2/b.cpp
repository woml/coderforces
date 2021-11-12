#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, prime = 1e9 + 7;

int q[N];

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> q[i];
        cout << n / 2 << endl;
        for (int i = 1; i < n; i += 2) {
            cout << i << " " << i + 1 << " " << min(q[i], q[i + 1]) << " " << prime << endl;
        }
    }

    return 0;
}