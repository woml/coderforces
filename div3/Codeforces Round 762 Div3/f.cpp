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

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, m, k;
        cin >> n >> m >> k;
        int up = (n + m - 1) / m, down = n / m;
        int cnt_up = n - down * m, cnt_down = (n - cnt_up * up) / down;
        int idx_up = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < cnt_up; j++) {
                printf("%d ", up);
                for (int l = 0; l < up; l++) {
                    int t = idx_up + l;
                    if (t > n) t -= n;
                    printf("%d ", t); 
                }
                idx_up += up;
                idx_up = idx_up > n ? idx_up - n : idx_up;
                printf("\n");
            }
            int t = idx_up;
            for (int j = 0; j < cnt_down; j++) {
                printf("%d ", down);
                for (int l = 0; l < down; l++) {
                    int p = t + l;
                    if (p > n) p -= n;
                    printf("%d ", p);
                }
                t += down;
                if (t > n) t -= n;
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}
