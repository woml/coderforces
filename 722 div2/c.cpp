#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 3e5 + 10;

typedef long long LL;
int h[N], e[N], ne[N], idx;
LL l[N], r[N];
LL f[N][2];
bool st[N];
bool father[N];

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u) {
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        dfs(j);
        f[u][0] += max(abs(l[u] - l[j]) + f[j][0], abs(l[u] - r[j]) + f[j][1]);
        f[u][1] += max(abs(r[u] - l[j]) + f[j][0], abs(r[u] - r[j]) + f[j][1]);
    }
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        idx = 0;
        memset(h, -1, sizeof h);
        memset(father, 0, sizeof father);
        memset(f, 0, sizeof f);
        memset(st, 0, sizeof st);
        for (int i = 1; i <= n; i++) scanf("%lld %lld", &l[i], &r[i]);
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            add(a, b);
            add(b, a);
        }
        dfs(1);
        printf("%lld\n", max(f[1][0], f[1][1]));
    }

    return 0;
}