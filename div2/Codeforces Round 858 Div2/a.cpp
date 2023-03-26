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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int t = d - b;
        if (t < 0) cout << "-1" << endl;
        else {
            a = a + t - c;
            if (a < 0) cout << "-1" << endl;
            else cout << a + t << endl;
        }
    }

    return 0;
}
