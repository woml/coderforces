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

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        bool ans1 = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i]) {
                swap(a[i], b[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[n] || b[i] > b[n]) {
                ans1 = false;
                break;
            }
        }
        if (ans1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
