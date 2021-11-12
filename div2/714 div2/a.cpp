#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int n, k;
        cin >> n >> k;
        int ans[1000];
        if (k > (n - 1) / 2) {
            cout << "-1" << endl;
        } else {
            int idx = 1;
            for (int i = 1; i <= k + 1 && 2 * i <= n + 1; i++) ans[2 * i - 1] = idx++;
            for (int i = 2 * k + 2; i <= n; i++) ans[i] = idx++;
            for (int i = 1; i <= k && 2 * k <= n; i++) ans[2*i] = idx++;
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
    return 0;
}