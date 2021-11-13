#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, INF = 1e9;

int sum[N][3];

int main(void) {
    int T;
    cin >> T;
    while (T --) {
        int len;
        cin >> len;
        string s;
        cin >> s;
        memset(sum, 0, sizeof sum);
        vector<int> a_q;
        for (int i = 1; i <= len; i++) {
            sum[i][s[i - 1] - 'a']++;
            if (s[i - 1] == 'a') a_q.push_back(i);
            sum[i][0] += sum[i - 1][0];
            sum[i][1] += sum[i - 1][1];
            sum[i][2] += sum[i - 1][2];
        }
        int ans = INF;
        if (sum[len][0] <= 1) ans = -1;
        if (ans != -1) {
            for (int i = 0; j )
        }
        cout << ans << endl;
    }

    /*

     for (int k = 1; k < a_q.size(); k++) {
                for (int i = 0, j = i + k; j < a_q.size(); i++, j++) {
                    int a = sum[a_q[j]][0] - sum[a_q[i] - 1][0];
                    int b = sum[a_q[j]][1] - sum[a_q[i] - 1][1];
                    int c = sum[a_q[j]][2] - sum[a_q[i] - 1][2];
                    if (a > b && a > c) {
                        ans = min(a_q[j] - a_q[i] + 1, ans);
                    }
                }
                if (ans != INF) break;
            }
            */

    return 0;
}