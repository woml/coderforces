#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL q[200020];

int main(void) {
    int n;
    LL k, x;
    cin >> n >> k >> x;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &q[i]);
    }
    sort(q, q + n, [](LL a, LL b){
        return a < b;
    });

    LL now = q[0], cnt = 1;

    for (int i = 1; i < n; i++) {
        if (now + x >= q[i]) continue;
        cnt++;
        pq.push(q[i] - q[i - 1]);
        now = q[i];
    }

    while (k) {
        if (cnt == 1) break;
        auto t = pq.top(); pq.pop();
        LL num = (t + x - 1) / x;
        num--;
        if (k < num) break;
        k -= num;
        cnt--;
    }

    cout << cnt << endl;
    return 0;
}