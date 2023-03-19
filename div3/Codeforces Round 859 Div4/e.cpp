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

void ask(int l, int r) {
    int n = r - l + 1;
    printf("? %d", n);
    for (int i = l; i <= r; i++) printf(" %d", i);
    cout << endl;
    cout.flush();
}

bool check(int l, int r, vector<int>& sum) {
    ask(l, r);
    int t;
    cin >> t;
    if (t == sum[r] - sum[l - 1]) return false;
    else return true;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> sum(n + 1), w(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
            sum[i] = sum[i - 1] + w[i];
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(l, mid, sum)) r = mid;
            else l = mid + 1;
        }
        cout << "! " << l << endl;
    }

    return 0;
}
