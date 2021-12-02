#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10, MOD = 998244353;
int arr[N], f[N][3];

void add(int& i, int j) {
    i = (i + j) % MOD;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        f[0][0] = f[0][1] = f[0][2] = 0;
        for (int i = 0; i < n; i++) {
            add(f[arr[i]][0], f[arr[i]][0]);
            if (arr[i] == 0) 
                add(f[arr[i]][0], 1);
            if (arr[i] >= 1)
                add(f[arr[i]][0], f[arr[i] - 1][0]);
            add(f[arr[i]][1], f[arr[i]][1]); 
            if (arr[i] == 1)
                add(f[1][1], 1);     // pure 1 count
            if (arr[i] > 1) {
                add(f[arr[i]][1], f[arr[i] - 2][0]);    // 00 11 22 4
                add(f[arr[i]][1], f[arr[i] - 2][2]);    // 00 11 22 44 22 4
            }
            add(f[arr[i]][2], f[arr[i]][2]);
            if (arr[i] + 2 <= n) {
                add(f[arr[i]][2], f[arr[i] + 2][1]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            add(ans, f[i][0]), add(ans, f[i][1]), add(ans, f[i][2]);
        }
        for (int i = 0; i <= n; i++)
            f[i][0] = f[i][1] = f[i][2] = 0;
        cout << ans << endl;
    }

    return 0;
}
