#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int q[N], R[N][32], cnt[N];
int n, k;

int get(int &x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            return i;
        }
    if (x > 1) {
        int res = x;
        x /= x;
        return res;
    }
}

void add(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            while (x % i == 0) {
                cnt[i]++;
                x /= i;
            }
        }
    if (x > 1) cnt[x]++;
}

void del(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            while (x % i == 0) {
                cnt[i]--;
                x /= i;
            }
        }
    if (x > 1) cnt[x]--;
}

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
    int i = 1, j = 1;
    while (j <= n) {
        int x = q[j];
        while (x > 1) {
            int t = get(x);
            while (cnt[t] > 0) {
                R[i][1] = j;
                del(q[i]);
                i++;
            }
        }
        add(q[j]);
        j++;
    }
    while (i != j) {
        R[i][1] = j;
        i++;
    }
    for (int i = 0; i <= 31; i++) R[n + 1][i] = R[n][i] = n + 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 2; j <= 30; j++) {
            R[i][j] = R[R[i][j - 1]][j - 1];
        }
    }
    for (int i = 1; i <= k; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = 0;
        for (int j = 30; j > 0; j--) {
            if (R[l][j] <= r) {
                l = R[l][j];
                ans += (1 << (j - 1));
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}