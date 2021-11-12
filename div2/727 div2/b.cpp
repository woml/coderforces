#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

LL s[N];

int main(void) {
    int n, q;
    cin >> n >> q;
    string t;
    cin >> t;
    for (int i = 1; i <= n; i++) {
        s[i] = t[i - 1] - 'a' + 1;
        s[i] += s[i - 1];
    }
    while (q --) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", s[r] - s[l - 1]);
    }
    return 0;
}