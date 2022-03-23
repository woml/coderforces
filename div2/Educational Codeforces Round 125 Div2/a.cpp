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

bool check(int x) {
    for (int i = 1; i <= 100; i++) {
        if (x == i * i) return true;
    }
    return false;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int x, y;
        cin >> x >> y;
        int t = x * x + y * y;
        if (t == 0) cout << "0" << endl;
        else if (check(t)) cout << "1" << endl;
        else cout << "2" << endl;
    }

    return 0;
}
