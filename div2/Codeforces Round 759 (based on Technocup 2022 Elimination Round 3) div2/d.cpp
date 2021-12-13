#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;

int arr[N], p[N];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T -- ) {
        int n;
        cin >> n;
        set<int> s;
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
            p[i] = i;
        }
        if (s.size() < n) flag = true;
        if (!flag) {
            int cycle = 0;
            for (int i = 1; i <= n; i++) {
                int px = find(arr[i]), py = find(i);
                if (p[px] == p[py]) cycle++;
                else p[px] = py;
            }
            flag = (n - cycle) % 2 == 0 ? true : false;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
