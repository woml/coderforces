#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int a[N];
LL ans;

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        ans = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        unordered_map<int, LL> h;
        for (int i = 1; i <= n; i++) {
            ans += h[a[i]] * (n + 1 - i);
            h[a[i]] += i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}