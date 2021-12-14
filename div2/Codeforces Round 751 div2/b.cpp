#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2020, M = 1e5 + 10;

int n;
int arr[N], cnt[N];
struct Query
{
    int k, idx, rank, ans;
}query[M];

bool change() {
    bool changed = false;
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[arr[i]]++;
    for (int i = 1; i <= n; i++) {
        if (cnt[arr[i]] != arr[i]) {
            changed = true;
        }
    }
    for (int i = 1; i <= n; i++) arr[i] = cnt[arr[i]];
    //for (int i = 1; i <= n; i++) cout << cnt[arr[i]] << " ";
    //cout << endl;
    return changed;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int k, idx;
            scanf("%d %d", &idx, &k);
            query[i] = {k, idx, i};
        }
        sort(query, query + q, [](Query a, Query b) {
            return a.k < b.k;
        });

        int now = 0;
        bool not_change = false;
        for (int i = 0; i < q; i++) {
            int k = query[i].k;
            if (!not_change) {
                while (now < k) {
                    if(!change()) not_change = true;
                    now++;
                    if (not_change) break;
                    //cout << "now = " << now << " k = " << k << " i = " << i << endl;
                }
            }
            query[i].ans = arr[query[i].idx];
        }
        sort(query, query + q, [](Query a, Query b) {
            return a.rank < b.rank;
        });
        for (int i = 0; i < q; i++) {
            printf("%d\n", query[i].ans);
        }
    }

    return 0;
}
