#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 50010;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int days;
        cin >> days;
        vector<int> cnt(N);
        vector<vector<int>> people(days + 1);
        for (int i = 1; i <= days; i++) {
            int n;
            cin >> n;
            for (int j = 1; j <= n; j++) {
                int x;
                scanf("%d", &x);
                people[i].push_back(x);
                cnt[x]++;
            }
        }
        vector<int> ans;
        bool find = true;
        for (int i = 1; i <= days; i++) {
            bool has = false;
            for (auto &p : people[i]) {
                if (cnt[p] == 1) {
                    ans.push_back(p);
                    has = true;
                    break;
                }
            }
            if (!has) {
                find = false;
                break;
            }
            for (auto &p : people[i]) cnt[p]--;
        }
        if (find) {
            for (int i = 0; i < days; i++) cout << ans[i] << " ";
            cout << endl;
        } else cout << "-1" << endl;
    }

    return 0;
}
