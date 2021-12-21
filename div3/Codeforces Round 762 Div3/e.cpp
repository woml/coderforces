#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int arr[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        vector<LL> s(n + 2), f(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            s[arr[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            s[i] += s[i - 1];
        }
        bool flag = true;
        vector<PII> q;
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                cout << s[i] << " ";
                if (s[i] > 1) q.push_back({i, s[i]});
            } else {
                if (s[i - 1] < i || !flag) {
                    cout << "-1 ";
                    flag = false;
                } else {
                    if (s[i] - s[i - 1] == 0) {
                        if (i != 1 && s[i - 1] - s[i - 2] == 0) {
                            int m = q.size(), t = q[m - 1].first;
                            q[m - 1].second--;
                            if (q[m - 1].second == 1) q.pop_back();
                            f[i] = f[i - 1] + i - 1 - t;
                            cout << f[i] << " ";
                        } else {
                            f[i] = f[i - 1];
                            cout << f[i] << " ";
                        }
                    } else {
                        if ((i == 1 && s[0] == 0) || s[i - 1] - s[i - 2] == 0) {
                            int m = q.size(), t = q[m - 1].first;
                            q[m - 1].second--;
                            if (q[m - 1].second == 1) q.pop_back();
                            f[i] = f[i - 1] + i - 1 - t;
                        } else {
                            f[i] = f[i - 1];
                        }
                        cout << f[i] + s[i] - s[i - 1] << " ";
                        if (s[i] - s[i - 1] > 1) q.push_back({i, s[i] - s[i - 1]});
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}
