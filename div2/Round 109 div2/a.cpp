#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int t;
    cin >> t;
    while (t --) {
        int x;
        cin >> x;
        int p;
        if (gcd(x, 100) != 1) {
            p = 100 / gcd(x, 100);
            cout << p << endl;
        } else {
            cout << 100 << endl;
        }
    }

    return 0;
}