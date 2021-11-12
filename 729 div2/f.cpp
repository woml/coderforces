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
        int n;
        cin >> n;
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            sum += (LL)x;
        }
        if (sum % n == 0) {
            cout << "0" << endl;
        } else {
            LL t = sum % n;
            LL p = n - t;
            cout << t * p << endl;
        }
    }
    return 0;
}