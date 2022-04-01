#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int tr[3][2 * N], M;
char s[N];

int lowbits(int x) { return x & -x; }

int query(int tr[], int x) {
    int res = 0;
    for (int i = x; i; i -= lowbits(i)) res += tr[i];
    return res;
}

void modify(int tr[], int x, int c) {
    for (int i = x; i <= M+M; i += lowbits(i)) tr[i] += c;
}

void init() {
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= M+M; j++)
            tr[i][j] = 0;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n >> s + 1;
        M = n + 1;
        init();

        modify(tr[0], M, 1);
        int pre = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            pre = pre + (s[i] == '-' ? 1 : -1);
            int p = (pre % 3 + 3) % 3;
            ans += query(tr[p], M + pre);
            modify(tr[p], M + pre, 1);
        }
        cout << ans << endl;
    }

    return 0;
}
