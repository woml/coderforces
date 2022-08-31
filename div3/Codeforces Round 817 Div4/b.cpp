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
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] == 'G') a[i] = 'B';
            if (b[i] == 'G') b[i] = 'B';
        }
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
