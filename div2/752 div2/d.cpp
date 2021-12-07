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
        if (b < a) cout << a + b << endl;
        else if (b == a) cout << a << endl;
        else {
            if (b % a == 0) cout << a << endl;
            else {
                cout << b - (b % a) / 2 << endl;
            }
        }
    }

    return 0;
}
