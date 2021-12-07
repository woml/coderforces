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
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int t = 1;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            int temp = t;
            while (temp && (arr[i] % (i - t + temp + 1) == 0)) temp--;
            if (temp == 0) {
                flag = false;
                break;
            }
            t++;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
