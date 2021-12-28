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

int arr[N], ans[N];

int main(void) {
    int T;
    cin >> T;
    while (T -- ) {
        int n;
        cin >> n;
        string s;
        for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        cin >> s;
        vector<PII> a, b;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                b.push_back({arr[i], i});
            } else a.push_back({arr[i], i});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int t = b.size(), j = 1;
        for (int i = 0; i < b.size(); i++) {
            ans[b[i].second] = j++;
        }
        for (int i = 0; i < a.size(); i++) {
            ans[a[i].second] = j++;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }

    return 0;
}
