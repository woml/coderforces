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
        if (b > a) swap(a, b);
        if (c > b) swap(b, c);
        if (b > a) swap(b, a);
        if (a == b + c) cout << "Yes" << endl;
        else {
            if (a == b && c % 2 == 0) cout << "Yes" << endl;
            else if (b == c && a % 2 == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
