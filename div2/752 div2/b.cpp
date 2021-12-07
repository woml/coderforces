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

int arr[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i > 0) {
                if(arr[i] <= arr[i - 1]) {
                    flag = false;
                }
            }
        }
        if (!flag || n % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
