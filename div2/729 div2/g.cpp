#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, MOD = 1e9 + 7;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int t = sum ^ i;
            sum = sum ^ t;
            cout << t << endl;
            cout.flush();
            int x;
            cin >> x;
            if (x == 1) break;
        }
    }
    return 0;
}