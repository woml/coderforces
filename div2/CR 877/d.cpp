#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
int n, q;

void solve() {
    string s;
    cin >> n >> q >> s;
    map<int, int> idx;
    //  even -> (   odd -> ) 
    for (int i = 0; i < n; i++) {
        if ((i & 1) && s[i] == '(') idx.insert({i, 0});
        else if (!(i & 1) && s[i] == ')') idx.insert({i, 1});
    }    
    while (q -- ) {
        int x;
        cin >> x;
        x--;
        if (s[x] == '(') {
            s[x] = ')';
            if (x & 1) idx.erase(x);
            else idx.insert({x, 1});
        } else {
            s[x] = '(';
            if (x % 2 == 0) idx.erase(x);
            else idx.insert({x, 0});
        }
        if (n & 1) cout << "No\n";
        else if (idx.empty()) cout << "Yes\n";
        else if (idx.begin()->second < idx.rbegin()->second) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
