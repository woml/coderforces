#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;
int q[N];

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> q[i];
        bool f = true;
        for (int i = 1; i <= n; i++) 
            if (q[i] != i) f = false;
        if (f) cout << "0" << endl;
        else {
            if (q[1] == n && q[n] == 1) {
                cout << "3" << endl;
            }
            else if (q[1] == 1 || q[n] == n) 
                cout << "1" << endl;
            else 
                cout << "2" << endl;
        }
    }

    return 0;
}