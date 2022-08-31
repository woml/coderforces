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

        // first is num, second is who 
        unordered_map<string, PII> cnt;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                string s;
                cin >> s;
                cnt[s].first++;
                cnt[s].second |= (1 << i);
            }
        }
        int x = 0, y = 0, z = 0;
        for (auto [k, v] : cnt) {
            if (v.first == 1) {
                x += 3 * (v.second & 1);
                y += 3 * (v.second >> 1 & 1);
                z += 3 * (v.second >> 2 & 1);
            } else if (v.first == 2) {
                x += 1 * (v.second & 1);
                y += 1 * (v.second >> 1 & 1);
                z += 1 * (v.second >> 2 & 1);
            }
        }
        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}
