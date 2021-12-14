#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int a[N], b[N], p[N], d[N], n;
bool can_arrive;

void dfs(int x) {
    if (x != n) {
        dfs(p[x]);
        cout << x << " ";
    }
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    queue<int> q;
    int high = n;
    q.push(n);
    can_arrive = false;
    while (q.size()) {
        auto t = q.front(); q.pop();
        if (t == 0) {
            cout << d[t] << endl;;
            can_arrive = true;
            dfs(t);
        }
        int down_to = t + b[t];     //  slide 
        int jump_to = max(down_to - a[down_to], 0);     //  In case p[-1] happen.
        // A step can arrive from [down_to - a[down_to] ~ down_to], using queue guarantee that if node first be visted, it must be minmum.
        for (int i = min(high, down_to - 1); i >= jump_to; i--) {
            p[i] = t;           //  p[i] represent for i is come from t, it is used to backtrack.
            d[i] = d[t] + 1;    //  step++
            q.push(i);          //  FIFO
        }
        // high represent for the highest location that not be visited, which means (high ~ n] has visited.
        high = min(high, jump_to - 1);
    }
    if (!can_arrive) cout << "-1" << endl;
    else cout << endl;
    return 0;
}
