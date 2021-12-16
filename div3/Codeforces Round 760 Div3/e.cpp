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

int a[N], b[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        LL total = 0;
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            total += b[i];
        }
        bool flag = true;
        int cnt = n * (n + 1) / 2;
        if (total % cnt) flag = false;
        total /= cnt;
        for (int i = 1; i <= n && flag; i++) {
            int j = i - 1;
            if (j == 0) j = n;
            LL t = total + b[j] - b[i];
            if (t <= 0) flag = false;
            if (t % n) flag = false;
            a[i] = t / n;
        }
        if (flag) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
