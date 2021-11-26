#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int a, b;
        cin >> a >> b;
        int d = abs(a - b);
        if (a < b) swap(a, b);
        if (a == b) {
            cout << a / 2 << endl;
        } else {
            d /= 2;
            if (d > b) {
                cout << b << endl;
            } else {
                b -= d;
                cout << d + b / 2 << endl; 
            }
        }
    }

    return 0;
}
