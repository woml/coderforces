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
        if (a == 0) cout << 1 << endl;
        else {
            cout << a + b * 2 + 1 << endl;
        }
    }

    return 0;
}
