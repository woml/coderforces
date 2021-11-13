#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) % 3 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}