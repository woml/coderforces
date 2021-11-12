#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 20, INF = 2e9;
int a[N];

int main(void) {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof a);
        int ans = 0, min_pos = INF;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            if (x <= 0) {
                a[ans++] = x;
            }
            else min_pos = min(x, min_pos);
        }
        sort(a, a + ans);
        bool f = true;
        for (int i = 0; i + 1 < ans; i++) {
            if (abs(a[i + 1] - a[i]) < min_pos) f = false;
        }
        if (f && min_pos != INF) printf("%d\n", ans + 1);
        else printf("%d\n", ans);
    }
    return 0;
}