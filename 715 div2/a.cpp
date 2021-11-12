#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2020;

int q[N][2];

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int i = 1, j = 1;
        for (int k = 1; k <= n; k++) {
            int x;
            cin >> x;
            if (x & 1) q[i++][0] = x;
            else q[j++][1] = x;
        }
        for (int k = 1; k < i; k++) cout << q[k][0] << " ";
        for (int k = 1; k < j; k++) cout << q[k][1] << " ";
        cout << endl;
    }
    return 0;
}