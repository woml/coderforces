#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 2e5 + 10, INF = 2e9;

int p[N], expolre[N];
struct Node {
    int x, y, r;
}a[N];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        p[fx] = fy;
        expolre[fy] = min(expolre[fy], expolre[fx]);
    }
}

bool check(int m, vector<int> &s) {
    int j = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] > m) {
            j = s.size() - i;
            break;
        }
    return j <= m + 1;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            cin >> a[i].x >> a[i].y >> expolre[i];
            a[i].r = i;
        }
        sort(a + 1, a + 1 + n, [](Node &a, Node &b){
            if (a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });
        for (int i = 1; i < n; i++) {
            if (a[i].x == a[i + 1].x && a[i + 1].y - a[i].y <= k) {
                merge(a[i].r, a[i + 1].r);
            }
        }
        sort(a + 1, a + 1 + n, [](Node &a, Node &b){
            if (a.y == b.y) return a.x < b.x;
            return a.y < b.y;
        });
        for (int i = 1; i < n; i++) {
            if (a[i].y == a[i + 1].y && a[i + 1].x - a[i].x <= k) {
                merge(a[i].r, a[i + 1].r);
            }
        }
        vector<int> ll;
        for (int i = 1; i <= n; i++)
            if (p[i] == i)
                ll.push_back(expolre[i]);
        sort(ll.begin(), ll.end());
        int l = 0, r = ll.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, ll)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}