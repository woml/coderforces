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

typedef struct Node {
    int h, w, rank;
    LL sum;
}NODE;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, q;
        cin >> n >> q;
        vector<vector<LL>> cnt(1001, vector<LL>(1001, 0));
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            cnt[h][w] += (LL)h * w;
        }

        for (int i = 1; i <= 1000; i++) {
            for (int j = 1; j <= 1000; j++) {
                cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
            }
        }

        while (q -- ) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            cout << cnt[hb - 1][wb - 1] - cnt[hs][wb - 1] - cnt[hb - 1][ws] + cnt[hs][ws] << endl;
        }
    }

    return 0;
}
