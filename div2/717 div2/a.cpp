#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int q[N];

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> q[i];
        int i = 0;
        while (k > 0) {
            while (q[i] > 0) {
                q[i]--;
                q[n - 1]++;
                k--;
                if (k == 0) break;
            }
            i++;
            if (i == n - 1) break;
        }
        for (int i = 0; i < n; i++) 
            cout << q[i] << " ";
        cout << endl;
    }

    return 0;
}