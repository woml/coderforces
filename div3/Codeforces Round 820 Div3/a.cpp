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
        int a, b, c;
        cin >> a >> b >> c;
        int x = abs(a - 1), y = abs(c - b) + abs(c - 1);
        if (x < y) cout << 1 << endl;
        else if (x > y) cout << 2 << endl;
        else cout << 3 << endl;

    }

    return 0;
}
