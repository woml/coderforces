#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6;

int e[2 * N], ne[2 * N], h[N], idx;

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, k;
        cin >> n >> k;
        vector<int> du(n + 1);
        idx = 0;
        for (int i = 0; i <= n; i++) h[i] = -1;
        for (int i = 0; i < n - 1; i ++) {
            int a, b;
            cin >> a >> b;
            add(a, b); add(b, a);
            du[a]++; du[b]++;
        }
        int del = 0;
        queue<int> q;
        if (n == 1) du[1] = 1;
        for (int j = 1; j <= n; j++) {
            if(du[j] == 1) {
                q.push(j); 
                du[j] = 0;
            }
        }
        for (int l = 0; l < k; l++) {
            vector<int> temp;
            while (q.size()) {
                auto t = q.front(); q.pop();
                for (int u = h[t]; ~u; u = ne[u]) {
                    int j = e[u];
                    du[j]--;
                    if (du[j] == 1) {
                        temp.push_back(j);
                        du[j] = 0;
                    }
                }
                del++;
                //cout << "t = " << t << " del = " << del << endl;
            }
            for (auto te : temp) q.push(te);
            if (temp.size() == 0) break;
        }
        cout << n - del << endl;
    }

    return 0;
}
