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
        vector<PII> arr(n);
        for (int i = 1; i <= n; i ++ ) {
            int x;
            cin >> x;
            arr[i - 1] = {x, i};
        }
        sort(arr.begin(), arr.end(), [](PII a, PII b){
            return a.first > b.first;
        });
        vector<int> ans(n + 1);
        ans[0] = 0;
        int idx = 1;
        LL cost = 0;
        for (auto t : arr) {
            idx++;
            if (idx & 1) {
                ans[t.second] = idx / 2;
                cost += (LL)ans[t.second] * t.first;
            } else {
                ans[t.second] = -(idx / 2);
                cost += (LL)(idx / 2) * t.first;
            }
        } 
        cout << cost * 2 << endl;
        for (int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
