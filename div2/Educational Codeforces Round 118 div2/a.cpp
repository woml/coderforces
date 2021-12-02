#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int x, a, y, b, len1 = 0, len2 = 0;
        cin >> x >> a >> y >> b;
        int t = x;
        while (t) {
            len1++;
            t /= 10;
        }
        t = y;
        while (t) {
            len2++;
            t /= 10;
        }
        if (len1 + a > len2 + b) {
            cout << ">" << endl;
        } else if (len1 + a < len2 + b) {
            cout << "<" << endl;
        } else {
            if (len1 > len2) {
                y *= pow(10, len1 - len2);
            } else if (len1 < len2) {
                x *= pow(10, len2 - len1);
            }
            if (x < y) cout << "<" << endl;
            else if (x > y) cout << ">" << endl;
            else cout << "=" << endl;
        }
    }

    return 0;
}
