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
        int w, h;
        cin >> w >> h;
        int a, b, c, d;
        cin >> a;
        vector<int> aa(a);
        for (int i = 0; i < a; i++) cin >> aa[i];
        cin >> b;
        vector<int> bb(b);
        for (int i = 0; i < b; i++) cin >> bb[i];
        cin >> c;
        vector<int> cc(c);
        for (int i = 0; i < c; i++) cin >> cc[i];
        cin >> d;
        vector<int> dd(d);
        for (int i = 0; i < d; i++) cin >> dd[i];
        LL ans = 0;
        if (aa.size() > 1) {
            LL d = aa[aa.size() - 1] - aa[0];
            int high = 0;
            if (bb.size() > 1) {
                high = h;
            } else {
                if (dd.size() > 1) high = dd[dd.size() - 1];
                if (cc.size() > 1) high = cc[cc.size() - 1];
            }
            ans = max(ans, d * high);
        }
        if (bb.size() > 1) {
            LL d = bb[bb.size() - 1] - bb[0];
            int high = 0;
            if (aa.size() > 1) {
                high = h;
            } else {
                if (dd.size() > 1) high = dd[0];
                if (cc.size() > 1) high = cc[0];
            }
            ans = max(ans, d * high);
        }
        if (cc.size() > 1) {
            LL d = cc[cc.size() - 1] - cc[0];
            int high = 0;
            if (dd.size() > 1) {
                high = w;
            } else {
                if (bb.size() > 1) high = bb[bb.size() - 1];
                if (aa.size() > 1) high = aa[aa.size() - 1];
            }
            ans = max(ans, d * high);
        }
        if (dd.size() > 1) {
            LL d = dd[dd.size() - 1] - dd[0];
            int high = 0;
            if (cc.size() > 1) {
                high = w;
            } else {
                if (bb.size() > 1) high = bb[0];
                if (aa.size() > 1) high = aa[0];
            }
            ans = max(ans, d * high);
        }

        cout << ans << endl;
    }

    return 0;
}
