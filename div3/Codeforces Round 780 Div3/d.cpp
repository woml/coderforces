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

typedef struct Node {
    int l, r;
}NODE;

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        vector<NODE> q;
        int cnt0 = 0, cnt2 = 0, flag = 0, last0 = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) {
                cnt0++;
                q.push_back({last0 + 1, i - 1});
                last0 = i;
            }
        }
        q.push_back({last0 + 1, n - 1});
        int max_v = 0, ans0, ans1;
        // cout << q.size() << endl;
        if (cnt0 == n) {
            cout << n << " " << 0 << endl;
        } else {
            for (int k = 0; k < q.size(); k++) {
                int l = q[k].l, r = q[k].r;
                if (l > r) continue;
                vector<int> cnt(4, 0);
                int cnt_neg = 0;
                // cout << "l = " << l << " r = " << r << endl;
                for (int i = l; i <= r; i++) {
                    if (arr[i] == -2) {
                        cnt_neg++;
                        cnt[0]++;
                    } else if (arr[i] == -1) {
                        cnt[1]++;
                        cnt_neg++;
                    } else if (arr[i] == 1) cnt[2]++;
                    else cnt[3]++;
                }
                if (cnt_neg % 2 == 0) {
                    int t = cnt[0] + cnt[3];
                    // cout << "!! t = " << t << endl; 
                    if (t >= max_v) {
                        ans0 = l;
                        max_v = t;
                        ans1 = n - 1 - r;
                        // cout << "??";
                    }
                } else {
                    // cout << "!";
                    int cnt2_l = 0, cnt2_r = 0, l_neg, r_neg;
                    for (int i = l; i <= r; i++) {
                        if (arr[i] == 2 || arr[i] == -2) cnt2_l++;
                        if (arr[i] < 0) {
                            l_neg = i;
                            break;
                        }
                    }
                    for (int i = r; i >= l; i--) {
                        if (arr[i] == 2 || arr[i] == -2) cnt2_r++;
                        if (arr[i] < 0) {
                            r_neg = i;
                            break;
                        }
                    }
                    // cout << "cnt = " << cnt[0] << " " << cnt2 << endl;
                    // cout << cnt2_l << " " << cnt2_r << endl;
                    if (cnt2_l <= cnt2_r) {
                        int t = cnt[0] + cnt[3] - cnt2_l;
                        // cout << t << endl;
                        if (t >= max_v) {
                            ans0 = l_neg + 1;
                            max_v = t;
                            ans1 = n - 1 - r;
                        }
                    } else {
                        int t = cnt[0] + cnt[3] - cnt2_r;
                        if (t >= max_v) {
                            ans0 = l;
                            max_v = t;
                            ans1 = n - r_neg;
                        }
                    }
                }
            }
            cout << ans0 << " " << ans1 << endl;
        }
    }

    return 0;
}
