#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;

int q[N], ans[N];

struct Node {
    int k, x, y;
}tr[N];

int main(void) {
    int n = 0, m = 0, total;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        scanf("%d %d", &k, &x);
        if (k == 1) {
            tr[i] = {k, x};
            n++;
        } else {
            scanf("%d", &y);
            tr[i] = {k, x, y};
        }
    }
    total = n;
    for (int i = m - 1; ~i; i--) {
        if (tr[i].k == 1) {
            if (q[tr[i].x] != 0) {
                ans[n--] = q[tr[i].x];
            } else ans[n--] = tr[i].x;
        } else {
            if (q[tr[i].y] != 0) 
                q[tr[i].x] = q[tr[i].y];
            else 
                q[tr[i].x] = tr[i].y;
        }
    }
    for (int i = 1; i <= total; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}
