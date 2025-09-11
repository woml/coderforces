#include <iostream>
#include <queue>

using namespace std;

class Solution {
public: // 2 4
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // live活着人员，spread能传播的人
        int mod = 1e9 + 7, live = 1, spread = 0;
        vector<int> p(n+1);
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            // 死亡人数
            if (i > forget) {
                live = ((live - p[i-forget]) % mod + mod) % mod;
                spread = ((spread - p[i-forget]) % mod + mod) % mod;
            }
            // 更新能spread人数
            if (i > delay) {
                spread = (spread + p[i - delay]) % mod;
                p[i] = spread;
            }
            live = (live + spread) % mod;
        }
        return live;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.peopleAwareOfSecret(4, 1, 3) << "\n";
    return 0;
}