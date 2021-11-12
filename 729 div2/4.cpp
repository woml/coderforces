#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int a[N];

int main(void) {
    int T;
    cin >> T;
    //cout << (2 & 1) << endl;
    while (T --) {
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                cout << "0 ";
            } else {
                int t = (a[i] & a[i - 1]);
                //cout << "i = " << i << " t = " << t << endl;
                if (t == a[i - 1]) {
                    cout << "0 ";
                } else {
                    int b = a[i - 1] | a[i];
                    cout << b - a[i] << " ";
                    a[i] = b;
                }
            }
        }
        cout << endl;
    }
    return 0;
}