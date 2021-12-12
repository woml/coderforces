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

PII t1[N], t2[N];
int e[N * 5], h[N], ne[N * 5], idx;

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void dfs(int u, vector<int> &st) {
    bool res = false;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = 1;
            dfs(j, st);
        }
    }
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        idx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            t1[i] = {x, i};
            h[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            t2[i] = {x, i};
        }
        sort(t1 + 1, t1 + n + 1, [](PII a, PII b){
            return a.first < b.first;
        });
        sort(t2 + 1, t2 + n + 1, [](PII a, PII b){
            return a.first < b.first;
        });
        for (int i = 1; i < n; i++) {
            add(t1[i].second, t1[i + 1].second);
            add(t2[i].second, t2[i + 1].second);
        }
        vector<int> st(n + 1, 0);
        st[t1[n].second] = 1;
        st[t2[n].second] = 1;
        dfs(t1[n].second, st);
        dfs(t2[n].second, st);
        for (int i = 1; i <= n; i++)
            if (st[i]) cout << "1";
            else cout << "0";
        cout << endl;
    }

    return 0;
}
