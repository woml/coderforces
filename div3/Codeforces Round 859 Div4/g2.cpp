#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int arr[N], st[40];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        memset(st, 0, sizeof st);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        
        st[0] = 1;
        int backup[20];
        bool can = true;
        if (arr[0] != 1) can = false;
        for (int i = 1; i < n && can; i++) {
            int x = arr[i];
            for (int j = 20; j >= 0; j--) backup[j] = st[j];
            // cout << endl;
            // for (int j = 20; j >= 0; j--) cout << backup[j] << "-";
            // cout << endl;
            for (int j = 20; j >= 0; j--) {
                if (x >> j & 1) {
                    int ask = 1;
                    // printf("j = %d\n", j);
                    for (int k = j; ~k; k--) {
                        // printf("k = %d, ask = %d, st = %d\n", k, ask, st[k]);
                        if (st[k] >= ask) {
                            st[k] -= ask;
                            ask = 0;
                            break;
                        }
                        ask -= st[k];
                        st[k] = 0;
                        ask *= 2;
                    }
                    if (ask != 0) {
                        can = false;
                        break;
                    }
                }
            }
            // cout << "i = " << i << endl;
            if (!can) break;
            else {
                for (int j = 20; j >= 0; j--) st[j] = backup[j];
                // cout << endl;
                for (int j = 20; j >= 0; j--) {
                    st[j] = backup[j];
                    if (arr[i] >> j & 1) {
                        st[j]++;
                    }
                    // cout << st[j] << "_";
                }
                // cout << endl;
                // for (int j = 20; j >= 0; j--) cout << st[j] << "-";
                // cout << endl;
            }
        }
        if (can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
