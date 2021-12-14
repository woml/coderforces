#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 200020;

LL arr[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        bool zero = true;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &arr[i]);
            if (arr[i] != 0) zero = false;
        }
        int p = 0;
        for (int j = 0; j < 30; j++) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                cnt += arr[i] >> j & 1;
            }
            if (cnt != 0) {
                if (p == 0) p = cnt;
                if (cnt > p) swap(cnt, p);
                p = gcd(p, cnt);
            }
        }

        //cout << "---> p = " << p << " <----";
        if (zero) {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
        } else {
            for (int i = 1; i <= p; i++) {
                if (p % i == 0) cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
