#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
LL R = 2e18;

string LL_s(LL a) {
    string res;
    while (a) {
        res.push_back((a & 1) + '0');
        a >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

LL s_LL(string s) {
    LL res = 0, p = 1;
    for (int i = s.size() - 1; ~i; i--) {
        if (s[i] == '1') res += p;
        p <<= 1;
    }
    return res;

}

string delete_leading_0(string s) {
    int idx = 0, n = s.size();
    while (idx < n && s[idx] == '0') idx++;
    return s.substr(idx);
}

int main(void) {
    LL x, y;
    cin >> x >> y;
    map<LL, int> st;
    queue<LL> q;
    q.push(x);
    st[x] = 1;
    bool find = false;
    while (q.size()) {
        LL t = q.front(), tnum; q.pop();
        if (t == y) {
            find = true;
            break;
        }
        string ts = LL_s(t), tn;
        tn = ts + "0";
        reverse(tn.begin(), tn.end());
        tn = delete_leading_0(tn);
        tnum = s_LL(tn);
        if (tnum <= R && st.count(tnum) == 0) {
            st[tnum] = 1;
            q.push(tnum);
        }
        tn = ts + "1";
        reverse(tn.begin(), tn.end());
        tn = delete_leading_0(tn);
        tnum = s_LL(tn);
        if (tnum <= R && st.count(tnum) == 0) {
            st[tnum] = 1;
            q.push(tnum);
        }
    }
    if (find) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
