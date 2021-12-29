#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 1e4 + 10;

struct Node {
    int l, r, len;
    int choose;
}tr[N];

int p[M], n;

int lowbit(int x) { return x & -x; }
int sum(int x) {
    int res;
    for (int i = x; i; i -= lowbit(i)) res += p[i];
    return res;
}
int add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i)) p[i] += c;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        cin >> n;
        vector<vector<int>> q(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> tr[i].l >> tr[i].r;
            tr[i].len = tr[i].r - tr[i].l + 1;
            q[tr[i].len].push_back(i);
        }
        memset(p, 0, sizeof p);
        for (int i = 1; i <= n; i++) add(i, 1);
        vector<int> st(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            bool undo = false;
            for (int j = 0; j < q[i].size(); j++) {
                int l = tr[q[i][j]].l, r = tr[q[i][j]].r;
                if (sum(r) - sum(l - 1) > 1) {
                    undo = true;
                } else {
                    for (int k = l; k <= r; k++) {
                        if (st[k] == 0) {
                            st[k] = 1;
                            tr[q[i][j]].choose = k;
                            add(k, -1);
                        }
                    }
                }
            }
            if (undo) i--;
        }
        for (int i = 0; i < n; i++) {
            cout << tr[i].l << " " << tr[i].r << " " << tr[i].choose << endl;
        }
        cout << endl;
    }

    return 0;
}
