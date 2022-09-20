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
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) idx.push_back(i);
        }
        if (idx.size() & 1) cout << "-1" << endl;
        else if (idx.size() == 0) cout << "0" << endl;
        else {
            int ans = 0, m = idx.size();
            if (m == 2) {
                if (idx[0] + 1 == idx[1]) {
                    cout << min(x, y * 2) << endl;
                }
                else cout << y << endl;
            }
            else {
                cout << (LL)y * m / 2 << endl;
            }
        }
    }

    return 0;
}
