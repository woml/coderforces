#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;

int n;
string s;
map<int, int> last;
int get(char c) {
    return pow(10, c - 'A');
}

int calc() {
    int v = 0;
    char c = 'A';
    for (int i = n - 1; ~i; i--) {
        if (s[i] < c) v -= get(s[i]);
        else v += get(s[i]);
        c = max(c, s[i]);
    }
    return v;
}

void solve() {
    cin >> s;
    n = s.size();
    last.clear();
    vector<int> pos;
    int ans = 0;
    char c = 'A';
    for (int i = n - 1; ~i; i--) {
        int j = s[i] - 'A';
        if (s[i] < c) ans -= get(s[i]);
        else ans += get(s[i]);
        if (!last.count(j)) last.insert({j, i});
        if (s[i] > c) pos.push_back(i);
        c = max(c, s[i]);
    }
    for (int i = 0; i < pos.size(); i++) {
        int c = s[pos[i]];
        for (int j = 'A'; j <= 'E'; j++) {
            if (j == c) continue;
            s[pos[i]] = j;
            ans = max(ans, calc());
        }
        s[pos[i]] = c;
    }
    c = 'A' - 1;
    vector<int> visit(10);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'A';
        if (!visit[c]) {
            visit[c] = 1;
            char p = s[i];
            for (int j = 0; j <= 4; j++) {
                s[i] = 'A' + j;;
                ans = max(calc(), ans);
                s[i] = p;
            } 
        }
    }

    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases -- ) {
        solve();
    }

    return 0;
}
