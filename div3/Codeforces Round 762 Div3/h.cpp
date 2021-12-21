#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int main(void) {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q -- ) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            swap(a[x], a[y]);
        } else {
            for (int i = 0; i < y; i++) {
                x = a[x];
            }
            cout << x << endl;
        }
    }
    return 0;
}