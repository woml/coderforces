#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, p = 998244353;

int C[5050][5050];
int cnt[N];

int main(void) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) C[j][i] = 1;
            else C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % p;
        }
    }
    queue<int> q;
    string s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        if (s[i - 1] == '0') cnt[i]++;
        else {
            if (q.size() == k) {
                
            } else q.push(i);
        }
    }
    return 0;
}
