#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, a[N];
ll ans[N];
vector<pair<int,int>> Q;

struct Node {
    int l, r;
    int v, minv;
    int lag;
}tr[N * 4];

void pushup(int u) {
    tr[u].minv = min(tr[u * 2].minv, tr[u * 2 + 1].minv);
}

void pushdown(int u) {
    if (tr[u].l != tr[u].r && tr[u].lag) {
        tr[u * 2].lag += tr[u].lag;
        tr[u * 2 + 1].lag += tr[u].lag;
        tr[u * 2].minv += tr[u].lag;
        tr[u * 2 + 1].minv += tr[u].lag;
        tr[u].lag = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, a[l], a[l]};
    else {
        int mid = (l + r) / 2;
        tr[u] = {l, r};
        build(u * 2, l, mid);
        build(u * 2 + 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v) {
    if (l > r) return;
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].lag += v;
        tr[u].minv += v;
    } else {
        int mid = (tr[u].l + tr[u].r) / 2;
        pushdown(u);
        if (l <= mid) modify(u * 2, l, r, v);
        if (r > mid) modify(u * 2 + 1, l, r, v);
        pushup(u);
    }
}

// query --> tr[1].minv

void solve() {
    int q;
    ll sum = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    sort(a + 1, a + 1 + n);
    for (int j = 1; j <= q; j++) {
        int k;
        cin >> k;
        Q.push_back({k, j});
    }
    Q.push_back({n, q + 1});
    sort(Q.begin(), Q.end());
    int last = 0, min_0, last_1;
    build(1, 1, n);
    for (int j = 0; j <= q; j++) {
        int id = Q[j].second, k = Q[j].first;
        if (k <= n) {
            bool del = false;
            for (int i = last + 1; i <= k; i++) {
                modify(1, 1, i, 1);
                if (i == n) {
                    min_0 = tr[1].minv;
                    del = true;
                }
            }
            int minv = tr[1].minv;
            ll diff = (ll)(k + 1) * k / 2;
            if (k == n)
                ans[id] = min_0 - (max(k - diff, (ll)0) + n - 1) / n;
            else 
                ans[id] = minv - (max(k - diff, (ll)0) + n - 1) / n;
            if (del) {
                modify(1, n, n, -1);
            }
            last = k;
        } else {
            if ((k - n) & 1) {
                modify(1, 1, n - 1, k - last);
                last = k;
                ans[id] = tr[1].minv;
                ll diff = (ll)(2 * k - n + 2) * (n - 1) / 2 + sum - (ll)tr[1].minv * n;
                k = (k - n + 1) / 2;
                ans[id] -= (max(k - diff, (ll)0) + n - 1) / n;
            } else {
                ans[id] = min_0 + k - n;
                ll diff = (ll)(2 * k - n + 1) * n / 2 + sum - (ll)ans[id] * n;
                k = (k - n) / 2;
                ans[id] -= (max(k - diff, (ll)0) + n - 1) / n;
            }
        }
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << " \n"[i == q];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}
