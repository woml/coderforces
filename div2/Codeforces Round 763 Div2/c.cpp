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

int n;
vector<int> arr;

bool check(int mid) {
    vector<int> t(n + 1, 0), q(n + 1, 0);
    for (int i = n; i >= 3; i--) {
        if (arr[i] + t[i] >= mid) {
            if (t[i] >= mid) {
                int d = arr[i] / 3;
                t[i - 1] += d;
                t[i - 2] += 2 * d;
            } else {
                int d = (arr[i] - mid + t[i]) / 3;
                t[i - 1] += d;
                t[i - 2] += 2 * d;
            }
        } else return false;
    }
    if (t[2] + arr[2] < mid || t[1] + arr[1] < mid) return false;
    return true;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        cin >> n;
        arr = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }

    return 0;
}
