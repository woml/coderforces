#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int l = 0;
        for (int i = 0; i < 2 * n; i++) {
            int x;
            cin >> x;
            if (x & 1) l++;
        }
        if (l == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}