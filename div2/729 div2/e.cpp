#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, MOD = 1e9 + 7;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        LL a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "0 0" << endl;
        } else {
            if (a > b) swap(a, b);
            if (a * 2 >= b) {
                LL t = b - a;
                if (a % t == b % t) {
                    LL p = a % t;
                    if (p < t - p) cout << b - a << " " << p << endl;
                    else cout << b - a << " " << t - p << endl; 
                } else {
                    cout << b - a << " " << a << endl;
                }
            } else {
                LL t = b - a;
                if (a % t == b % t) {
                    LL p = a % t;
                    if (p < t - p) cout << b - a << " " << p << endl;
                    else cout << b - a << " " << t - p << endl; 
                } else {
                    cout << b - a << " " << a << endl;
                }
            }
        }
    }
    return 0;
}