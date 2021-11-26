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

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (arr[0] != n && arr[n - 1] != n) {
            cout << "-1" << endl;
        } else {
            if (arr[0] == n) {
                cout << n << " ";
                for (int i = n - 1; i > 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            } else {
                for (int i = n - 2; i >= 0; i--) {
                    cout << arr[i] << " ";
                }
                cout << n << endl;
            }
        }
    }

    return 0;
}
