#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void ask(LL a, LL b) {
    printf("? %lld %lld\n", a, b);
    cout << flush;
}

int main(void) {
    unordered_map<LL, int> cnt;
    LL ans = 0, times = -1;
    for (int i = 2; i <= 26; i++) {
        ask(1, i);
        LL x, y;
        cin >> x;
        ask(i, 1);
        cin >> y;      
        if (x == -1) {
            ans = i - 1;
            break;
        }
        if (x != y) cnt[x + y]++;
    }
    if (ans == 0) {
        for (auto [k, v] : cnt) {
            if (k != -1 && v > times) {
                times = v;
                ans = k;
            }
        }
    }
    cout << "! " << ans << endl;
    cout << flush;

    return 0;
}
