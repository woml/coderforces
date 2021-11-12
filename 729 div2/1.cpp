#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {
    int T;
    cin >>  T;
    while (T --) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        if (a == c || b == d) {
            if (a == c && c == e) {
                if (b > d) {
                    if (b > f && f > d) {
                        cout << abs(a - c) + abs(b - d) + 2 << endl;
                    } else {
                        cout << abs(a - c) + abs(b - d) << endl;
                    }
                } else {
                    if (b < f && f < d) {
                        cout << abs(a - c) + abs(b - d) + 2 << endl;
                    } else {
                        cout << abs(a - c) + abs(b - d) << endl;
                    }
                }
            } else if (b == d && d == f) {
                if (a > c) {
                    if (a > e && e > c) {
                        cout << abs(a - c) + abs(b - d) + 2 << endl;
                    } else {
                        cout << abs(a - c) + abs(b - d) << endl;
                    }
                } else {
                    if (a < e && e < c) {
                        cout << abs(a - c) + abs(b - d) + 2 << endl;
                    } else {
                        cout << abs(a - c) + abs(b - d) << endl;
                    }
                }
            } else {
                cout << abs(a - c) + abs(b - d) << endl;
            }
        } else {
            cout << abs(a - c) + abs(b - d) << endl;
        }
    }
    return 0;
}