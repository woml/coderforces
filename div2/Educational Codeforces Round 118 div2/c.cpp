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

bool check(vector<int> &arr, LL mid, LL h) {
    LL cnt = 0, left = mid;
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] - arr[i] <= mid) {
            cnt += arr[i + 1] - arr[i];
        } else {
            cnt += mid;
        }
    }
    cnt += mid;
    return cnt >= h;
}

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        LL h;
        cin >> n >> h;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        LL l = 1, r = h;
        while (l < r) {
            LL mid = l + r >> 1;
            if (check(arr, mid, h)) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}
