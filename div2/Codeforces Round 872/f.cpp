#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

template<class T>
struct BIT {
    T c1[N], c2[N];
    int size;
    void init(int sz) {
        size = sz;
        for (int i = 1; i <= sz; i++) c1[i] = c2[i] = 0;
    }
    void add(int x, T v) {
        assert(x <= N);
        int i = x;
        for (; x <= size; x += x & (-x)) {
            c1[x] += v;
            c2[x] += i * v;
        }
    }
    T query(int x) {
        int n = x;
        T res = 0;
        for (; x; x -= x & (-x)) {
            res += (n + 1) * c1[x] - c2[x];
        }
        return res;
    }
};

int n, q, a[N];
ll ans[N];
BIT<ll> t1, t2;
vector<array<int, 4>> event[N];
set<int> s; // 某个值最后一次出现的下标
int last[N]; // 某个值的下表是否存在, 和其值

void update(int l, int r, ll v1, ll v2) {
    t1.add(l, v1);
    t1.add(r + 1, -v1);
    t2.add(l, v2);
    t2.add(r + 1, -v2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    t1.init(n), t2.init(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        event[x - 1].push_back({l, r, -1, i});
        event[y].push_back({l, r, 1, i});
    }

    s.insert(0);
    for (int i = 1; i <= n; i++) {
        update(i, i, i, (ll)(n - i + 1) * i);
        s.insert(i);
        if (last[a[i]]) {
            int u = last[a[i]];
            int x = *--s.lower_bound(u);
            int y = *s.upper_bound(u);
            if (y == n + 1) y = i;
            update(x + 1, u, y - u, (ll)(y - u) * (n - i + 1));
            s.erase(u);
        }
        last[a[i]] = i;
        for (auto [l, r, k, id] : event[i]) {
            ans[id] += k * (t2.query(r) - t2.query(l - 1) - (t1.query(r) - t1.query(l - 1)) * (n - i));
        }
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";

    return 0;
}