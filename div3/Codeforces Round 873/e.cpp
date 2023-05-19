#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int p[N], sz[N];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> in(n + 1);
    map<pair<int,int>, int> cnt;
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x;
        y = i;
        if (x > y) swap(x, y);
        if (!cnt.count({x, y})) {
            cnt[{x, y}] = 1;
            in[x]++, in[y]++;
            int a = find(x), b = find(y);
            p[b] = a;
        }
    }   
    int t = 0, con = 0;
    map<int, int> can;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            can[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] == 1) {
            t++;
            can[find(i)] = 0;
        }
    }
    t /= 2;
    for (auto [k, v] : can) {
        if (v == 1) con++;
    }
    if (t == 0) cout << con << " " << con << "\n";
    else cout << con + 1 << " " << con + t << "\n";
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int cases;
    std::cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}

