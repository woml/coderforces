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
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        int d1 = y - 1, d2 = m - y, d3 = x - 1, d4 = n - x;
        if (d1 <= d && d3 <= d) cout << "-1" << endl;
        else if (d2 <= d && d4 <= d) cout << "-1" << endl;
        else if (d1 <= d && d2 <= d) cout << "-1" << endl;
        else if (d3 <= d && d4 <= d) cout << "-1" << endl;
        else cout << n + m - 2 << endl;
    }

    return 0;
}
